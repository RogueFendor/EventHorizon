#ifndef CONTROL_H
#define CONTROL_H

#include <QDialog>

namespace Ui {
class Control;
}

class Control : public QDialog
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();

private:
    Ui::Control *ui;
};

#endif // CONTROL_H
