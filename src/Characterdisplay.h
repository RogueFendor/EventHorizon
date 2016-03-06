#ifndef CHARACTERDISPLAY_H
#define CHARACTERDISPLAY_H

#include <QToolBox>

namespace Ui {
class CharacterDisplay;
}

class CharacterDisplay : public QToolBox
{
    Q_OBJECT

public:
    explicit CharacterDisplay(QWidget *parent = 0);
    ~CharacterDisplay();
    void setLives(QString lives);
    void setOutput(QString output);
    void setChallenges(QString challenges);
    void setGreeting(QString greeting);
    void setType(int id);

private:
    Ui::CharacterDisplay *ui;
};

#endif // CHARACTERDISPLAY_H
