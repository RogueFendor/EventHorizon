#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <QString>
#include "Character.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <string>
#include<Question.h>
#include<MainCharacter.h>
#include<Challenger.h>

using namespace std;

class ZorkUL {

private:

    Question* currentQuestion;
    bool gameStat;
    bool challengerExists;
    QString *str;
	void createRooms();
    void createMainCharacter();
    void createChallenger(int id);

    void createItems();
    int generateRandomNumber();

public:
	ZorkUL();
    Room *currentRoom;
    void setChallengerNeverExisted();
    bool ChallengerNeverExisted(int challId);
    MainCharacter *currentPlayer;
    Challenger *currentChallenger =NULL;
    bool getChallengerExists();
    void setChallengerExists(bool n);
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
    vector<int> compMap;
};
#endif /*ZORKUL_H_*/
