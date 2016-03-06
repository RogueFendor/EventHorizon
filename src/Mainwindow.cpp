#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include"ZorkUL.h"
#include<iostream>
#include<QDebug>
#include<QApplication>
#include<QLabel>
#include<QFont>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap bkgnd("../CS076_GUI/img/background_1.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
     game = new ZorkUL;     
     PlInfo();
     wellcome();
     ui->playLayout->addWidget(currentPlayer,0,1);
     ui->playLayout->addWidget(currentChallenger,0,2);
}
void MainWindow::wellcome(){
         QString n =game->playerInfo();
         currentString =n;
         currentPlayer->setGreeting(n);
         qApp->processEvents();
}
void MainWindow::PlInfo(){

    currentPlayer = new CharacterDisplay;
    currentPlayer->setType(1);
    currentChallenger = new CharacterDisplay;
    currentChallenger->setHidden(true);

}
void MainWindow(){

}
MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_buttonChall_clicked()
{

}
