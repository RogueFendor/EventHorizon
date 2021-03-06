#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<string>
#include "ZorkUL.h"
#include"Characterdisplay.h"

namespace Ui {

  class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStringList getQStringList();
    void wellcome();
    void PlInfo();
    void ChalInfo();
    void setTextAreas();
    void displayMessage();
    void renderQuestion();
    bool challengerExists;
    void setChallengerExist(bool n);
    bool getChallengerExists();
    const QString *danger;
    const QString *safe;
    void destroyWindow();
    QString imageName();
    ZorkUL *game;
    CharacterDisplay *currentPlayer;
    CharacterDisplay *currentChallenger;
    Question *question;
    QPixmap *currentPixMap;
    QPalette *currentPallete;
    QString currentString;




public slots:

      void verifyAnswer(bool);


private slots:



    void on_buttonChall_clicked();

    void on_buttonNorth_clicked();

    void on_buttonEast_clicked();

    void on_buttonSouth_clicked();

    void on_buttonWest_clicked();

    void on_showNewCharacter_clicked();

    void on_itemBox_currentIndexChanged(int index);

    void on_CompareItem_clicked();

    void on_teleporter_clicked();

private :

    Ui::MainWindow *ui;
    void setNewChallenger();
};
#endif // MAINWINDOW_H
