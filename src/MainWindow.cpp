#include "MainWindow.h"
#include "ui_mainwindow.h"
#include"ZorkUL.h"
#include<iostream>
#include<QDebug>
#include<QApplication>
#include<QMessageBox>
#include<QLabel>
#include<QFont>
#include<QRadioButton>
#include "Question.h"
#include<QStringList>

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
     ui->buttonChall->setEnabled(false);
}
void MainWindow::wellcome(){
         QString n =game->playerInfo();
         currentString =n;
         ui->textArea1->setText(game->printWelcome());
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
    qDebug()<<game->getGameStat();
    if(game->getGameStat()==true){
        qDebug()<<game->getGameStat();
        QString n =game->challengerInfo();
        currentString =n;
        currentChallenger->setGreeting(n);
        currentChallenger->setType(game->idRequest());
        currentChallenger->setHidden(false);
        ui->buttonChall->setEnabled(true);
        ui->buttonChall->setText("NewChallenge");
        ui->buttonChall->setStyleSheet("color: rgb(79, 193, 185);");
        qApp->processEvents();
        displayMessage();
    }
}
void MainWindow::on_buttonChall_clicked()
{


   qDebug()<<"test buton is disabled";
      question = new Question;
      qDebug()<<game->idRequest();
      question->setUp(game->idRequest());
      if(question->getCounter()==0){
         renderQuestion();
      }
      ui->buttonChall->setEnabled(false);
}
void MainWindow::renderQuestion(){

   QStringList n = question->getQuestion(question->getCounter()+1).split(",");
   QLabel* question = new QLabel;
   QWidget *header =new QWidget;
   QFont serifFont( "Times", 12);
   QGridLayout *headerLayout = new QGridLayout;

   qDebug()<<n.at(0);

   question->setText(n.at(0));
   question->setStyleSheet("color: rgb(142,142,56 	); font:bold");
   question->setFont(serifFont);
   question->setWordWrap(true);
   question->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

   headerLayout->addWidget(question,0,0);

   header->setStyleSheet("background-color: rgb(209,238,238 )");
   header->setLayout(headerLayout);

   ui->textArea2->addWidget(header,0,0);
   QWidget *displayArea =new QWidget;
   displayArea->setStyleSheet("background-color: rgb(0,255,255 );");
   QGridLayout *widgetLayOut = new QGridLayout;

   for(int i=1;i<n.size() -1;i++){

      QRadioButton* b = new QRadioButton;
      QFont font( "Times", 12);

      b->setText(n.at(i));
      b->setFont(font);
      connect(b,SIGNAL(clicked(bool)),this,SLOT(verifyAnswer(bool)));

      widgetLayOut->addWidget(b,i,0);
      b->adjustSize();
   }
  displayArea->setLayout(widgetLayOut);
  ui->textArea2->addWidget(displayArea);
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
    setTextAreas();
}

void MainWindow::on_buttonSouth_clicked()
{
    game->go("south");
    setNewChallenger();
    setTextAreas();
}

void MainWindow::on_buttonWest_clicked()
{
    game->go("west");
    setNewChallenger();
    setTextAreas();
}

void MainWindow::on_showNewCharacter_clicked()
{

}


void  MainWindow::verifyAnswer(bool){


}


void MainWindow::displayMessage(){
    QMessageBox::information(
        this,
        tr("EventHorizon"),
        tr("New Challenges Available!\nSelect Challenges from control panel") );

}
