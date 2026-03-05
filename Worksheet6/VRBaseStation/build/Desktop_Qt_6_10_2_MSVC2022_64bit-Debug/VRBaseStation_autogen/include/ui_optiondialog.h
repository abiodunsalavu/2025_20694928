/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QCheckBox *checkBox;
    QSpinBox *redSpinBox;
    QSpinBox *blueSpinBox;
    QSpinBox *greenSpinBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName("OptionDialog");
        OptionDialog->resize(379, 279);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(OptionDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 63, 20));
        nameLineEdit = new QLineEdit(OptionDialog);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(80, 20, 113, 28));
        checkBox = new QCheckBox(OptionDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 60, 92, 25));
        redSpinBox = new QSpinBox(OptionDialog);
        redSpinBox->setObjectName("redSpinBox");
        redSpinBox->setGeometry(QRect(10, 90, 44, 29));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(redSpinBox->sizePolicy().hasHeightForWidth());
        redSpinBox->setSizePolicy(sizePolicy);
        redSpinBox->setMaximum(255);
        blueSpinBox = new QSpinBox(OptionDialog);
        blueSpinBox->setObjectName("blueSpinBox");
        blueSpinBox->setGeometry(QRect(10, 120, 44, 29));
        sizePolicy.setHeightForWidth(blueSpinBox->sizePolicy().hasHeightForWidth());
        blueSpinBox->setSizePolicy(sizePolicy);
        blueSpinBox->setMaximum(255);
        greenSpinBox = new QSpinBox(OptionDialog);
        greenSpinBox->setObjectName("greenSpinBox");
        greenSpinBox->setGeometry(QRect(10, 150, 44, 29));
        sizePolicy.setHeightForWidth(greenSpinBox->sizePolicy().hasHeightForWidth());
        greenSpinBox->setSizePolicy(sizePolicy);
        greenSpinBox->setMaximum(255);
        label_2 = new QLabel(OptionDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 63, 20));
        label_3 = new QLabel(OptionDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 120, 63, 20));
        label_4 = new QLabel(OptionDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 150, 63, 20));

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, OptionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, OptionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QCoreApplication::translate("OptionDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("OptionDialog", "Name", nullptr));
        checkBox->setText(QCoreApplication::translate("OptionDialog", "Visible", nullptr));
        label_2->setText(QCoreApplication::translate("OptionDialog", "Red", nullptr));
        label_3->setText(QCoreApplication::translate("OptionDialog", "Blue", nullptr));
        label_4->setText(QCoreApplication::translate("OptionDialog", "Green", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
