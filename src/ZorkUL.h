#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "Character.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <string>
#include<Question.h>

using namespace std;

class ZorkUL {
private:
	Room *currentRoom;
    Character* currentPlayer;
    Character* currentChallenger =NULL;
    Question* currentQuestion;
    bool gameStat;
    QString *str;
	void createRooms();
    void createMainCharacter();
    void createChallenger(int id);

    void createItems();
    int generateRandomNumber();

public:
	ZorkUL();
    bool getGameStat();
    void setGameStat(bool n);
    int createChallengerID();
    int idRequest();
    int returnNumberOfChallenges();
    QString returnRoom();
    QString returnLive();
    // QString return
    QString playerInfo();
    QString roomInfo();
    QString challengerInfo();
    QString printWelcome();
    QString genericStringsToQString(string str);
    QString printHelp();
    QString displayItems();
    QString itemDetails(int id);

    QString playChallenge(int challengeNum);
    void showQuestions();
    void teleport();
    void go(string direction);
    string available_rooms [10];
    map<int, Room*> tmpMap;
};

#endif /*ZORKUL_H_*/
