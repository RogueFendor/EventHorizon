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
        QPixmap pixN(":/new/largeImg/img/north.png");
        QIcon icon(pixN);
        ui->buttonNorth->setIcon(pixN);
        QPixmap pixW(":/new/largeImg/img/west.png");
        QIcon icon2(pixW);
        ui->buttonWest->setIcon(pixW);
        QPixmap pixE(":/new/largeImg/img/east.png");
        QIcon icon3(pixE);
        ui->buttonEast->setIcon(pixE);
        QPixmap pixS(":/new/largeImg/img/south.png");
        QIcon icon4(pixS);
        ui->buttonSouth->setIcon(pixS);
    // ui->centralWidget->setStyleSheet("border-image: url(:/new/largeImg/img/background_1.jpg)");
     game = new ZorkUL;     
     PlInfo();
     wellcome();
     ui->playLayout->addWidget(currentPlayer,0,1);
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
    ui->liveBar->setValue(100);
    ui->liveBar->setStyleSheet("QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}");



}
void MainWindow(){

}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setNewChallenger(){
    if(game->getGameStat()==true ){
        currentChallenger = new CharacterDisplay;
        ui->playLayout_2->addWidget(currentChallenger,0,1);
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

   qDebug()<<"test button is disabled";
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
   QFont serifFont( "Times", 12);

   question->setText(n.at(0));
   question->setStyleSheet("color: rgb(142,142,56 	); font:bold");
   question->setFont(serifFont);
   question->setWordWrap(true);
   question->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
   ui->questionLayout->addWidget(question);




   QWidget *displayArea =new QWidget;
   displayArea->setStyleSheet("background-color: rgb(0,255,255 );");

   if(n.size()>1){
       for(int i=1;i<n.size() -1;i++){
       qDebug()<<"Test i"<<i;
          QRadioButton* b = new QRadioButton;
          QLabel *label = new QLabel;
          label->setStyleSheet("color: rgb(30,144,255 	); font:bold");
          QString ans;

          switch(i){
            case 1:
              ans = "0";
              break;
            case 2:
              ans =  "1";
              break;
            case 3:
              ans= "2";
              break;
            case 4:
              ans= "3";
              break;
            case 5:
              ans="4";
              break;
          }
         label->setText(n.at(i));
          b->setObjectName(ans);
          connect(b,SIGNAL(clicked(bool)),this,SLOT(verifyAnswer(bool)));
          b->adjustSize();
          ui->textArea2->addWidget(label,i,0);
          ui->textArea2->addWidget(b,i,1);
       }
   }
   else{



   }

}
void MainWindow::on_buttonNorth_clicked()
{
    game->go("north");
     qDebug()<<"N1"<<game->getGameStat();
     if(game->createChallengerID()<40){
       setNewChallenger();
     }
     qDebug()<<"N2"<<game->getGameStat();
    setTextAreas();

}
void MainWindow::setTextAreas(){
    ui->textArea1->setText(game->returnRoom());
    qApp->processEvents();
}
void MainWindow::on_buttonEast_clicked()
{
    game->go("east");
     qDebug()<<"E1"<<game->getGameStat();
    if(game->createChallengerID()<40){
      setNewChallenger();
    }
     qDebug()<<"E2"<<game->getGameStat();
    setTextAreas();"border-image:url(:/img/congrats.jpg);";
}

void MainWindow::on_buttonSouth_clicked()
{
    game->go("south");
     qDebug()<<"S1"<<game->getGameStat();
     if(game->createChallengerID()<40){
        setNewChallenger();
     }
      qDebug()<<"S2"<<game->getGameStat();
    setTextAreas();
}

void MainWindow::on_buttonWest_clicked()
{
    game->go("west");
     qDebug()<<"W1"<<game->getGameStat();
     if(game->createChallengerID()<40){
       setNewChallenger();
     }
      qDebug()<<"W2"<<game->getGameStat();
    setTextAreas();
}

void MainWindow::on_showNewCharacter_clicked()
{

}


void  MainWindow::verifyAnswer(bool){

  if(question->verifyAnswer(MainWindow::sender()->objectName())==true){
       question->setCounter(question->getCounter()+1);

      if(question->getNumOfQuestions() > question->getCounter()){
          game->currentChallenger->setNumOfChallenges(game->currentChallenger->getNumOfChallenges()-1);
          destroyWindow();
          renderQuestion();
          qApp->processEvents();
      }
      else{
           game->setGameStat(true);
           destroyWindow();
           qApp->processEvents();
           delete currentChallenger;
           delete game->currentChallenger;
           game->setChallengerExists(false);
      }
  }
  else{
      qDebug()<<"Test Output2";
      game->currentPlayer->setLive(game->currentPlayer->getLive()-1);
       QString n =game->playerInfo();
       currentPlayer->setGreeting(n);
         ui->liveBar->setValue(ui->liveBar->value()-20);
         if(ui->liveBar->value()<50)
             ui->liveBar->setStyleSheet("QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}");
         qApp->processEvents();
         if(game->currentPlayer->getLive()==0){
             QMessageBox::information(
                 this,
                 tr("EventHorizon"),
                 tr("Game Over You Lost Buddy!") );
             exit(1);
         }
  }
}
void MainWindow::destroyWindow(){
 int len = ui->textArea2->count();
 delete ui->questionLayout->itemAt(0)->widget();
    for (int i = 0; i <len ; ++i)
    {
          delete ui->textArea2->itemAt(0)->widget();
          qDebug()<<"Still here Though"<<i;
    }
}
void MainWindow::displayMessage(){
    QMessageBox::information(
        this,
        tr("EventHorizon"),
        tr("New Challenges Available!\nSelect Challenges from control panel") );

}
