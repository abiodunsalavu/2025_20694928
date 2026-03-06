#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "ModelPart.h"
#include "ModelPartList.h"
#include <QFileDialog>
#include "optiondialog.h"
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkNew.h>
#include <QVTKOpenGLNativeWidget.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*connect function for push button */
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    /*connect function for status update message */
    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
    /*connect function for handle tree view clicked */
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::handleTreeClicked);
    /*connect function for second button */
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::handleButton2);
    /* Create / allocate the ModelList */
    this->partList = new ModelPartList("Parts List");

    ui->treeView->addAction(ui->actionItemOptions);
    ui->treeView->setContextMenuPolicy(Qt::ActionsContextMenu);
    /* Link it to the tree view in the GUI */
    ui->treeView->setModel(this->partList);

    /* Manually create a model tree.
   There are much better and more flexible ways of doing this,
   e.g., with nested functions. This is just a quick example.
*/
    ModelPart *rootItem = this->partList->getRootItem();

    /* Add 3 top-level items */
    for (int i = 0; i < 3; i++) {
        /* Create strings for both data columns */
        QString name = QString("TopLevel %1").arg(i);
        QString visible("true");

        /* Create child item */
        ModelPart *childItem = new ModelPart({name, visible});

        /* Append to tree top-level */
        rootItem->appendChild(childItem);

        /* Add 5 sub-items to each top-level item */
        for (int j = 0; j < 5; j++) {
            QString subName = QString("Item %1,%2").arg(i).arg(j);
            QString subVisible("true");

            ModelPart *childChildItem = new ModelPart({subName, subVisible});

            /* Append to the current top-level child */
            childItem->appendChild(childChildItem);
        }
    }
    renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    ui->vtkWidget->setRenderWindow(renderWindow);
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);
    vtkNew<vtkCylinderSource> cylinder;
    cylinder->SetResolution(8);
    vtkNew<vtkPolyDataMapper> cylinderMapper;
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());
    vtkNew<vtkActor> cylinderActor;
    cylinderActor->SetMapper(cylinderMapper);
    cylinderActor->GetProperty()->SetColor(1.0,0.,0.35);
    cylinderActor->RotateX(30.0);
    cylinderActor->RotateY(-45.0);
    renderer->AddActor(cylinderActor);
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton() {
    emit statusUpdateMessage(QString("Add button was clicked"), 0);
}

void MainWindow::handleTreeClicked() {
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());
    QString text = selectedPart->data(0).toString();
    emit statusUpdateMessage(QString("The seleced item is: ")+text, 0);
}
void MainWindow::on_actionOpen_File_triggered(){
    emit statusUpdateMessage(QString("Open File action triggered"), 0 );
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C:\\",
        tr("STL (*.stl);;Text Files (*.txt)")
        );
}
void MainWindow::handleButton2()
{
    // Get the selected item from tree view
    QModelIndex index = ui->treeView->currentIndex();

    if (index.isValid()) {
        // Get pointer to the selected ModelPart
        ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

        // Create and show the dialog
        OptionDialog dialog(this);
        dialog.setModelPart(selectedPart);

        if (dialog.exec() == QDialog::Accepted) {
            dialog.updateModelPart();
            emit statusUpdateMessage(QString("Part properties updated"), 0);

            // Refresh the tree view to show updated name
            ui->treeView->update();
        } else {
            emit statusUpdateMessage(QString("Edit cancelled"), 0);
        }
    } else {
        emit statusUpdateMessage(QString("Please select a part first"), 0);
    }
}

void MainWindow::on_actionItemOptions_triggered() {
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

    if (selectedPart) {
        OptionDialog dialog(this);
        dialog.setModelPart(selectedPart); // Load current data into dialog

        if (dialog.exec() == QDialog::Accepted) {
            dialog.updateModelPart(); // Save data from dialog to part
            ui->treeView->update();   // Refresh the view to show changes
        }
    }
}
