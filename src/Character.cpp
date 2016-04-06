
#include "Character.h"
#include "Item.h"
#include <map>
#include<string>
#include <sstream>
#include<iostream>
using namespace std;



Character::Character(){

}

Character::~Character(void){

}

void Character::setChallenge(int num){
      switch(num){
          case 2:
            challengeDescriptor = 2;
          break;
          case 3:
            challengeDescriptor = 3;
          break;
          case 4:
            challengeDescriptor = 4;
          break;
          case 5:
            challengeDescriptor = 5;
          break;
          case 6:
            challengeDescriptor = 6;
          break;
          case 7:
            challengeDescriptor = 7;
          break;
          case 8:
            challengeDescriptor = 8;
          break;
          case 9:
            challengeDescriptor = 9;
          break;
          case 10:
            challengeDescriptor = 10;
          break;
          case 11:
            challengeDescriptor = 11;
          break;
          case 12:
            challengeDescriptor = 12;
          break;
      }
}
int Character::getChallenge(){
    return challengeDescriptor;
}
void Character::setCharacter(int id){
    switch (id) {
        // create main Character
        /*  TODO
         * set its description
         * set lives
         *
        */
        case 1:{
        setCharacterName("Roger Doger");
        setGender("Male");
        setLive(5);
        setNumOfChallenges(0);
        //addItems(new Item(info, 1, "INFORMATION"));MainCharacter
        }
        break;
        // create Character in Room AI
        case 2:
         setCharacterName("Quark");
         setGender("Hermothermalprodite");
         setNumOfChallenges(2);
         setChallenge(2);
        break;
        // create Character in Room i
        case 3:
            setCharacterName("Dark_One");
            setGender("Female");
            setNumOfChallenges(1);
            setChallenge(3);
            addItems(new Item("FN21020", 1, "INFORMATION"));

        break;
        // create character in room h
        case 4:
            setCharacterName("Cedric-Junel-Valencia");
            setGender("Male");
            setNumOfChallenges(1);
            setChallenge(4);
            addItems(new Item("Onion"));
        break;
        // create Character in Room g
        case 5:
            setCharacterName("Sphinx");
            setGender("Take your pick");
            setNumOfChallenges(1);
            setChallenge(5);
            addItems(new Item("Nothing"));
        break;
        // create Character in Room f
        case 6:
            setCharacterName("Lafod");
            setGender("Male");
            setNumOfChallenges(1);
            setChallenge(6);
            addItems(new Item("Candle"));
        break;
        // create Character in Room e
        case 7:
            setCharacterName("Reltih");
            setGender("Female");
            setNumOfChallenges(1);
            setChallenge(7);
            addItems(new Item("Bottle"));
        break;
        // create Character in Room d
        case 8:
            setCharacterName("Anilst");
            setGender("Etheral-Stub");
            setNumOfChallenges(2);
            setChallenge(8);
            addItems(new Item("Clock"));
        break;
        // create Character in Room c
        case 9:
            setCharacterName("Sujes");
            setGender("Solo-Unisteral");
            setNumOfChallenges(1);
            setChallenge(9);
            addItems(new Item("Laptop"));
        break;
        // create Character in Room b
        case 10:
           setCharacterName("Tanas");
           setGender("Male");
           setNumOfChallenges(1);
           setChallenge(10);
           addItems(new Item("Edible Seaweed"));
        break;
        // create Character in Room a compare
        case 11:
           setCharacterName("Galf");
           setGender("Male");
           setNumOfChallenges(1);
        break;
        // create Character in Room z not yet created
        case 12:
           setCharacterName("Chris Sexton");
           setGender("Male");
           setNumOfChallenges(12);
           setChallenge(12);
        break;
    default: break;
    }

}


//just return the Characters long description
// return short description
void Character::setNumOfChallenges(int challenges){
    numOfChallenges = challenges;
}

int Character::getNumOfChallenges(){
    return numOfChallenges;
}
void Character::setItemCheck(string item){
    this->itemChecker= item;
}

string Character::getItemCheck(){

    return this->itemChecker;
}


void Character::setCharacterName(string name){
   description = name;
}
void Character::setLive(int live){
    lives = live;
}
int Character::getLive(){
    return this->lives;
}


void Character::setGender(string gender){
    this->gender = gender;
}
string Character::getGender(){
    return gender;
}
void Character::addItems(Item *item){
    itemsInCharacter.push_back(*item);

}
Item Character::getItemFromChallenger(){

    return itemsInCharacter[0];
}
string Character::getAllItems(){
    int len = itemsInCharacter.size();
    stringstream allItems;
    allItems << "You  have ";
    allItems << len << " Items available\n\n";
    for(int i =0; i< len;i++){
        allItems << "\nItem Number: " << i << itemsInCharacter.at(i).getLongDescription();
    }
    return allItems.str();
}



//just return the Characters long description



// return short description
string Character::shortDescription(){
      string ret = this->description;
      return ret;
}
