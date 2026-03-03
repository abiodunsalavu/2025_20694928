#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ModelPartList.h"
#include "ModelPart.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // This is what the compiler is currently missing:
signals:
    void statusUpdateMessage(QString message, int timeout);

public slots:
    void handleButton();
    void handleTreeClicked();


private:
    Ui::MainWindow *ui;
    ModelPartList * partList;
};
#endif // MAINWINDOW_H
