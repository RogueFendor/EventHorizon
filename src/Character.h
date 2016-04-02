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
     int lives;
     int numOfChallenges;
     int challengeDescriptor;
     string gender;
     string itemChecker;
     void setChallenge(int num);

     void setCharacterName(string name);
     void setGender(string gender);


public:
     Item getItemFromChallenger();
     string description;
     vector <Item> itemsInCharacter;
    virtual string longDescription()=0;
    Character();
    ~Character();
    Character(int id);
    void setLive(int live);
    int getChallenge();
    void setCharacter(int i);
    int getLive();
    string getGender();
    int getNumOfChallenges();
    void setNumOfChallenges(int challenges);
    void addItems(Item *item);
    void setItemCheck(string item);
    string getItemCheck();
    string shortDescription();
    string getAllItems();
};
#endif /*CHARACTER_H_*/
