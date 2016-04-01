#include "Character.h"
#include "Item.h"
#include <map>
#include<string>
#include <sstream>
#include<iostream>
#include<Challenger.h>
using namespace std;



Challenger::Challenger(int id){
   setCharacter(id);
   challPlayed = false;
}
Challenger::Challenger(){

}
Challenger::~Challenger(void){

}
void Challenger::setChallengerID(int id){
          challengerID = id;
}
int Challenger::getChallengerID(){
    return challengerID;
}

void Challenger::setChallengePlayed(bool n){
    challPlayed = n;
}
bool Challenger::getChallengePlayed(){
    return challPlayed;
}
string Challenger::longDescription(){
    stringstream character;
    character << "<font color='green'>Role: Challenger</font><br/>";
    character << "<font color='green'>Challenges:"<< getNumOfChallenges()<<"</font>";
    character << "<br/><font color='red'><b>Click on Challenges<br/>for list of Challenges</b></font>";
    return character.str();
}
