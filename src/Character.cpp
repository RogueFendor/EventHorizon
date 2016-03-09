
#include "Character.h"
#include "Item.h"
#include <map>
#include<string>
#include <sstream>
#include<iostream>
using namespace std;


Character::Character(int id){
   setCharacter(id);
}
Character::Character(){

}

void Character::setChallengerID(int id){
          challengerID = id;
}
int Character::getChallengerID(){
    return challengerID;
}
Character::~Character(void){
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
        setCharacter("Roger Doger");
        setGender("Male");
        setLive(5);
        setNumOfChallenges(0);
        //addItems(new Item(info, 1, "INFORMATION"));
        }
        break;
        // create Character in Room AI
        case 2:
         setCharacter("Quark");
         setGender("Hermothermalprodite");
         setNumOfChallenges(2);
         setChallenge(2);
        break;
        // create Character in Room i
        case 3:
            setCharacter("Dark_One");
            setGender("Female");
            setNumOfChallenges(1);
            setChallenge(3);
            addItems(new Item("FN21020", 1, "INFORMATION"));

        break;
        // create character in room h
        case 4:
            setCharacter("Cedric-Junel-Valencia");
            setGender("Male");
            setNumOfChallenges(1);
            setChallenge(4);
            setItemCheck("Onion");
        break;
        // create Character in Room g
        case 5:
            setCharacter("Sphinx");
            setGender("Take your pick");
            setNumOfChallenges(1);
            setChallenge(5);
            setItemCheck("Nothing");
        break;
        // create Character in Room f
        case 6:
            setCharacter("Lafod");
            setGender("Male");
            setNumOfChallenges(1);
            setChallenge(6);
            setItemCheck("Candle");
        break;
        // create Character in Room e
        case 7:
            setCharacter("Reltih");
            setGender("Female");
            setNumOfChallenges(1);
            setChallenge(7);
            setItemCheck("Bottle");
        break;
        // create Character in Room d
        case 8:
            setCharacter("Anilst");
            setGender("Etheral-Stub");
            setNumOfChallenges(2);
            setChallenge(8);
            setItemCheck("MushroomClock");
        break;
        // create Character in Room c
        case 9:
            setCharacter("Sujes");
            setGender("Solo-Unisteral");
            setNumOfChallenges(1);
            setChallenge(9);
            setItemCheck("Foot");
        break;
        // create Character in Room b
        case 10:
           setCharacter("Tanas");
           setGender("Male");
           setNumOfChallenges(1);
           setChallenge(10);
           setItemCheck("Edible Seaweed");
        break;
        // create Character in Room acompare
        case 11:
           setCharacter("Galf");
           setGender("Male");
           setNumOfChallenges(1);
           addItems(new Item("-3,+5,-2,-10,+5,+6",2,"INFORMATION"));
        break;
        // create Character in Room z not yet created
        case 12:
           setCharacter("Chris Sexton");
           setGender("Male");
           setNumOfChallenges(12);
           setChallenge(12);
        break;
    default: break;
    }

}


void Character::setItemCheck(string item){
    this->itemChecker= item;
}
//just return the Characters long description
string Character::longDescription(){

  stringstream character;
  character << "<font color='yellow'>Name: "<< description<<"</font><br/>";
  if(description.compare("Roger Doger")==0){
  character << "<font color='green'>Role: Captain</font><br/>";
  character << "<font color='green'>Gender: "<< getGender()<<"</font><br/>" ;
  character << "<font color='green'>Lives left: "<< getLive()<<"</font><br/>";
  character << "<font color='green'>Challenges completed: "<<getNumOfChallenges()<<"</font><br/>" ;
  }
  else{
      character << "<font color='green'>Role: Challenger</font><br/>";
      character << "<font color='green'>Challenges:"<< getNumOfChallenges()<<"</font>";
      character << "<br/><font color='red'><b>Click on Challenges<br/>for list of Challenges</b></font>";
  }
  return character.str();
}

// return short description
string Character::shortDescription(){
      string ret = this->description;
      return ret;
}
void Character::setCharacter(string name){
   description = name;
}
void Character::setLive(int live){
    lives = live;
}
int Character::getLive(){
    return this->lives;
}

void Character::setNumOfChallenges(int challenges){
    numOfChallenges = challenges;
}

int Character::getNumOfChallenges(){
    return numOfChallenges;
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
void Character::setGender(string gender){
    this->gender = gender;
}
string Character::getGender(){
    return gender;
}
void Character::addItems(Item *item){
    itemsInCharacter.push_back(*item);

}
/*
Item* Character::useItems(Item* item){

}
*/
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
