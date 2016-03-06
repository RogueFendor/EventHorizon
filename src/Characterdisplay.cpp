#include "Characterdisplay.h"
#include "ui_characterdisplay.h"

CharacterDisplay::CharacterDisplay(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::CharacterDisplay)
{
    ui->setupUi(this);
}

CharacterDisplay::~CharacterDisplay()
{
    delete ui;
}

void CharacterDisplay::setGreeting(QString greeting){

ui->lable_greeting->setText(greeting);
ui->lable_greeting->adjustSize();
//Quick Test does ignore work?

}
void CharacterDisplay::setType(int id){
    switch(id){
     case 1: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char8.jpg)");
             ui->button1->setText("Items");
             ui->button2->setText("Take");
             ui->button3->setText("Help");

             ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
             ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
             ui->button3->setStyleSheet("color: rgb(79, 193, 185);");

        break;
     case 2: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char1.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 3: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char2.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 4: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char3.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 5: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char4.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 6: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char5.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 7: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char6.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;
     case 8: ui->widget->setStyleSheet("border-image: url(:/new/largeImg/img/char6.jpg)");
        ui->button1->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button2->setStyleSheet("color: rgb(79, 193, 185);");
        ui->button3->setStyleSheet("color: rgb(79, 193, 185);");
        break;

    }

}
