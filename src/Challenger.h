
#ifndef CHALLENGER_H
#define CHALLENGER_H

//#include "ZorkUL.h"
#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"


using std::vector;

using namespace std;

class Challenger : public Character {

public:

 Challenger();
 Challenger(int i);
 ~Challenger();

 int challengerID;

 bool challPlayed = false;


 bool getChallengePlayed();
 void setChallengePlayed(bool n);


 void setChallengerID(int id);
 int getChallengerID();
 string longDescription();
};
#endif // CHALLENGER_H
