#ifndef OPTIONALDIALOG_H
#define OPTIONALDIALOG_H

#include <QDialog>
#include "ModelPart.h"

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();

    // Methods to interact with ModelPart
    void setModelPart(ModelPart* part);
    void updateModelPart();

private:
    Ui::OptionDialog *ui;
    ModelPart* m_part;  // Store the part being edited
};

#endif // OPTIONALDIALOG_H
