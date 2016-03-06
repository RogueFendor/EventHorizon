#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<string>
#include "ZorkUL.h"
#include<Characterdisplay.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void wellcome();
    void PlInfo();
    void ChalInfo();

    ~MainWindow();
    CharacterDisplay *currentPlayer;
    CharacterDisplay *currentChallenger;
    ZorkUL *game;
    QPixmap *currentPixMap;
    QPalette *currentPallete;
    QString currentString;

private slots:

    void on_buttonChall_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
