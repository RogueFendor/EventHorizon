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
     int challengerID;
     int lives;
     int numOfChallenges;
     void setCharacter(string name);
     void setGender(string gender);
     void setItemCheck(string item);

     string getGender();

public:
    Character();
    ~Character();
    Character(int id);

    int getNumOfChallenges();
    void setNumOfChallenges(int challenges);
    void addItems(Item *item);
    void setLive(int live);
    int getLive();

    void setChallengerID(int id);
    int getChallengerID();

    void setCharacter(int id);

    int getChallenge();

    string getItemCheck();
    string shortDescription();
    string longDescription();

    void createMainCharacter(Item *i);
    string getAllItems();
    Item* useItems(Item* item);

};
#endif /*CHARACTER_H_*/
