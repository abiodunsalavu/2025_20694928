#include "optiondialog.h"
#include "ui_optiondialog.h"

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),           // Call base class constructor
    ui(new Ui::OptionDialog),  // Create the UI
    m_part(nullptr)            // Initialize part to null
{
    ui->setupUi(this);         // Setup the UI from the .ui file
}

OptionDialog::~OptionDialog()
{
    delete ui;  // Clean up the UI
}

void OptionDialog::setModelPart(ModelPart* part)
{
    m_part = part;
    if (m_part != nullptr) {
        // 1. Get Name from Index 0
        ui->nameLineEdit->setText(m_part->data(0).toString());

        // 2. Get Visibility using your class function
        ui->checkBox->setChecked(m_part->visible());

        // 3. Get RGB values using your class functions
        ui->redSpinBox->setValue(m_part->getColourR());
        ui->greenSpinBox->setValue(m_part->getColourG());
        ui->blueSpinBox->setValue(m_part->getColourB());
    }
}

void OptionDialog::updateModelPart()
{
    if (m_part != nullptr) {
        // 1. Update Name (Index 0) using the 'set' function from your header
        m_part->set(0, ui->nameLineEdit->text());

        // 2. Update Visibility using your class function
        m_part->setVisible(ui->checkBox->isChecked());

        // 3. Update Colour using your class function
        m_part->setColour(ui->redSpinBox->value(),
                          ui->greenSpinBox->value(),
                          ui->blueSpinBox->value());
    }
}
