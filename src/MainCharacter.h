#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
//#include "ZorkUL.h"
#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"

using std::vector;

using namespace std;

class MainCharacter : public Character{

public:
 bool challPlayed = false;
 MainCharacter();
 MainCharacter(int id);
 ~MainCharacter();
 bool challengePlayed();
 void challengePlayed(bool n);
 string longDescription();

};
#endif // MAINCHARACTER_H
