#ifndef CHARACTER_H_
#define CHARACTER_H_
//#include "ZorkUL.h"
#include <string>
#include <vector>
#include "Item.h"

using std::vector;
using namespace std;


class Character {
private:
     string description;
     vector <Item> itemsInCharacter;
     string gender;
     string itemChecker;
     int challengeDescriptor;
     void setChallenge(int num);

     int lives;
     int numOfChallenges;
     int completedChallenges;
     bool challengeCompleted;
     void setCharacter(string name);
     void setNumOfChallenges(int number);
     void setGender(string gender);
     void setItemCheck(string item);

     string getGender();

public:
    Character();
    ~Character();
    Character(int id);

    int getNumberOfChallenges();
    void addItems(Item *item);
    void setLive(int live);
    int getLive();
    void setCharacter(int id);
    void comeToLive();

    int getChallenge();

    void setChallengesComplete(int);
    int getChallengesComplete();

    string getItemCheck();
    string shortDescription();
    string longDescription();

    void createMainCharacter(Item *i);
    string getAllItems();
    Item* useItems(Item* item);

};
#endif /*CHARACTER_H_*/
