#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ModelPart.h"
#include "ModelPartList.h"
#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

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
public slots:
    void handleButton();
    void handleTreeClicked();
    void on_actionOpen_File_triggered();
    void handleButton2();
    void on_actionItemOptions_triggered();
    void updateRender();
    void updateRenderFromTree(const QModelIndex& index);

signals:
    void statusUpdateMessage (const QString & message, int timeout);
private:
    Ui::MainWindow *ui;
    ModelPartList *partList;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer;
};
#endif // MAINWINDOW_H
