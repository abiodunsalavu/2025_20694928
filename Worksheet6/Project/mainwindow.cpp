#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    connect(this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage);
    /* Create / allocate the ModelList */
    this ->partList = new ModelPartList("PartsList");
    /* Link it to the treeview in the GUI */
    ui->treeView->setModel(this->partList);
    /* Manually create a model tree - there is a much better and more flexible ways of doing this,
     with nested functions being a example, this is just a quick example for a starting point*/
    ModelPart *rootItem = this->partList->getRootItem();
    /* Add 3 top level items */
    for (int i =0; i <3; i++) {
        /* Create strings for both data columns */
        QString name = QString("TopLevel %1").arg(i);
        QString visible("true");
        /* Create Child Item */
        ModelPart *childItem = new ModelPart({name, visible});
        /*Append to tree top-level */
        rootItem->appendChild(childItem);
        /* Add 5 sub-items */
        for (int j =0; j < 5; j++){
            QString name = QString("Item %1,%2").arg(i).arg(j);
            QString visible("true");
            ModelPart *childChildItem = new ModelPart({ name, visible});
            /*Append to Parent*/
            childItem->appendChild(childChildItem);
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton(){
    emit statusUpdateMessage( QString("Add button was clicked"), 5000);
}

