#include "MainWindow.h"
#include "ui_mainwindow.h"
#include"ZorkUL.h"
#include<iostream>
#include<QDebug>
#include<QApplication>
#include<QLabel>
#include<QFont>
#include "Question.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap bkgnd(":/new/largeImg/img/background_1.jpg");
        bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    // ui->centralWidget->setStyleSheet("border-image: url(:/new/largeImg/img/background_1.jpg)");
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



void MainWindow::setNewChallenger(){
    QString n =game->challengerInfo();
    currentString =n;
    currentChallenger->setGreeting(n);
    currentChallenger->setType(game->idRequest());
    currentChallenger->setHidden(false);
    qApp->processEvents();

}
void MainWindow::on_buttonChall_clicked()
{
    /*
    if(){
      question = new Question;
      question->setUp(game->idRequest());
    }
    */
}

void MainWindow::on_buttonNorth_clicked()
{
    game->go("north");
    setNewChallenger();
    setTextAreas();

}
void MainWindow::setTextAreas(){
    ui->textArea1->setText(game->returnRoom());
    qApp->processEvents();
}
void MainWindow::on_buttonEast_clicked()
{
    game->go("east");
    setNewChallenger();
}

void MainWindow::on_buttonSouth_clicked()
{
    game->go("south");
    setNewChallenger();
}

void MainWindow::on_buttonWest_clicked()
{
    game->go("west");
    setNewChallenger();
}

void MainWindow::on_showNewCharacter_clicked()
{

}
