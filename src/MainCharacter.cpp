#include "Character.h"
#include "MainCharacter.h"
#include "Item.h"
#include <map>
#include<string>
#include <sstream>
#include<iostream>
using namespace std;


MainCharacter::MainCharacter(int id){
   setCharacter(id);
   challPlayed = false;
}
MainCharacter::MainCharacter(){

}
MainCharacter::~MainCharacter(){

}
void MainCharacter::challengePlayed(bool n){
    challPlayed = n;
}
bool MainCharacter::challengePlayed(){
    return challPlayed;
}
string MainCharacter::longDescription(){
    stringstream character;
    character << "<font color='yellow'>Name: "<< description<<"</font><br/>";
    character << "<font color='green'>Role: Captain</font><br/>";
    character << "<font color='green'>Gender: "<< getGender()<<"</font><br/>" ;
    character << "<font color='green'>Lives left: "<< getLive()<<"</font><br/>";
    character << "<font color='green'>Challenges completed: "<<getNumOfChallenges()<<"</font><br/>" ;
    return character.str();
}
