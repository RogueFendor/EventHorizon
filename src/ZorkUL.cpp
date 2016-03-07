#include <iostream>
#include<ctime>
#include<cstdlib>
#include<map>
#include"Character.h"

// nice little lib for string streaming
#include<sstream>
#include "ZorkUL.h"
#include <QApplication>
#include<QtDebug>
#include<QMessageBox>

using namespace std;
// Our Constructor
ZorkUL::ZorkUL() {
/*
  two methods to initialize rooms and main character
*/
    createMainCharacter();
    createRooms();
}
/*
This Method creates the main character of the game
and adds an item to the Character
*/
void ZorkUL::createMainCharacter(){

    currentPlayer =new Character(1);
    string info="If you are reading this please.."
                "You must find Emilies AI we named"
                "him 'Goran'....he can help you!"
                "\nSomething happened and most likely"
                "\nyou are the last remaining live member"
                "\nof the crew."
                "\nBe carefull there are shady and weird"
                "\nbeings spread across the Ship who are"
                "\nmost likely hostile towards you."
                "\nGood luck...\n";
    currentPlayer->addItems(new Item(info,1,"INFO"));

}
// instantiate Challenger
void ZorkUL::createChallenger( int id){

    currentChallenger =new Character(id);

}
/*
Method to create all rooms
and adding items into them
*/

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;

	a = new Room("a");

    a->addItem(new Item("x", 1, "Test"));
    a->addItem(new Item("y", 2, "Test"));

    b = new Room("b");

    //b->addItem(new Item("xx", 3, 33,0));


    c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
    i = new Room("i");
    j = new Room("j");
    k = new Room("k");
    k->addItem(new Item("yy", 4, 44,0));

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, j, i);
    e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(d,NULL,NULL,NULL);
    k->setExits(j,NULL,NULL,NULL);
    tmpMap[1]= a;
    tmpMap[2]= b;
    tmpMap[3]= c;
    tmpMap[4]= d;
    tmpMap[5]= e;
    tmpMap[6]= f;
    tmpMap[7]= g;
    tmpMap[8]= h;
    tmpMap[9]= i;
    tmpMap[10]=j;

    currentRoom = k;
}

/*
 *  Main play routine.  Loops until end of play.
 */
// Wellcome :-)

QString ZorkUL::printWelcome() {
     QString info =QString("<font color='red'><b>Wellcome to</b></font></br><font color='blue'><h3>EventHorizon</h3>");
     //Wellcome to EventHorizon\nCaptain Rogers We are happy to see you!";
     return info;
}

QString ZorkUL::playerInfo(){

    QString player = QString::fromStdString(currentPlayer->longDescription());
    return player;
}

QString ZorkUL::challengerInfo(){
    QString info = QString::QString::fromStdString(currentChallenger->longDescription());
    return info;
}

QString ZorkUL::roomInfo(){
   QString room = QString::QString::fromStdString(currentRoom->longDescription());
   return room;
}
QString ZorkUL::itemDetails(int id){
    QString itemDetail = QString::QString::fromStdString(currentRoom->getItemDetails(id));
    return itemDetail;
}

QString ZorkUL::genericStringsToQString(string str){
    return QString::QString::fromStdString(str);
}

void ZorkUL::teleport(){
    bool runGen =true;
    int number;
    while(runGen){
      number = generateRandomNumber();
      if(tmpMap.find(number)== tmpMap.end()){
      }
      else{
          map<int, Room*>::iterator telPortTo = tmpMap.find(number);
          Room *tmpRoom = telPortTo->second;
          if(tmpRoom->shortDescription().compare(currentRoom->shortDescription())==0){
             continue;
          }
          else{
            //~currentRoom();
            currentRoom = tmpRoom;
            if(currentRoom->shortDescription().compare("j")==0){
                roomInfo();
            }
            else{
                // chech here for challenge status of main character
                // check challenges here if not finished previously
                //do nothing here otherwise
                if(currentChallenger->getChallengesComplete()>0){
                  roomInfo();
                }
                else
                {
              //      ~currentChallenger();
                    createChallenger(getChallengerID());
                    roomInfo();
                    challengerInfo();
                }

            }
            runGen = false;
          }
      }
    }
}
QString ZorkUL::printHelp() {
    QString help = "????????? We are fucked too!";
    return help;
}
int ZorkUL::generateRandomNumber(){
    int max =10;
    int randomNumber;
    srand(time(0));
    randomNumber=(rand() % max) +1;

    return randomNumber;

}


void ZorkUL::go(string direction){
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL){
       //we'll se what to do here
    }
	else
	{
        //~currentRoom();
		currentRoom = nextRoom;
        roomInfo();
        // check challenges here if not finished previously
        //do nothing here otherwise
        if(currentChallenger->getChallengesComplete() < currentChallenger->getNumberOfChallenges()){
          // do nothing keep going here
        }
        else
        {
           // ~currentChallenger();
            createChallenger(getChallengerID());
            challengerInfo();
        }
	}
}

int ZorkUL::getChallengerID(){
    string tmp = currentRoom->shortDescription();
    if(tmp.compare("a")==0){
       return 11;
    }
    else if(tmp.compare("b")==0){
       return 10;
    }
    else if(tmp.compare("c")==0){
       return 9;
    }
    else if(tmp.compare("d")==0){
       return 8;
    }
    else if(tmp.compare("e")==0){
       return 7;
    }
    else if(tmp.compare("f")==0){
       return 6;
    }
    else if(tmp.compare("g")==0){
       return 5;
    }
    else if(tmp.compare("h")==0){
       return 4;
    }
    else if(tmp.compare("i")==0){
       return 3;
    }
    else if(tmp.compare("j")==0){
       return 2;
    }
    else if(tmp.compare("z")==0){
       return 12;
    }
}
