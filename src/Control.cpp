#include "Control.h"
#include "ui_control.h"

Control::Control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
}

Control::~Control()
{
    delete ui;
}
