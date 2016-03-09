#include <iostream>
#include<ctime>
#include<cstdlib>
#include<map>
#include"Character.h"

// nice little lib for string streaming
#include<sstream>
#include "ZorkUL.h"
#include <QApplication>
#include<QDebug>
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
    currentChallenger->setChallengerID(id);

}
/*
Method to create all rooms
and adding items into them
*/

void ZorkUL::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *ai, *start,
         *bridge, *chr_a, *chr_b, *dcr_a, *dcr_b, *e_room_a, *e_room_b;

    a = new Room("a");
    b = new Room("b");
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    ai = new Room("AI");//was room j
    start = new Room("START"); //was room k

    bridge = new Room("BRIDGE");
    chr_a = new Room("CHR-A");
    chr_b = new Room("CHR-B");
    dcr_a = new Room("DCR-A");
    dcr_b = new Room("DCR-B");
    e_room_a = new Room("E-ROOM-A");
    e_room_b = new Room("E-ROOM-B");
    /*la = new Room("");
    lb = new Room("");
    lc = new Room("");
    ld = new Room("");
    le = new Room("");
    lf = new Room("");*/

    a->addItem(new Item("x", 1, "Test"));
    a->addItem(new Item("y", 2, "Test"));
    start->addItem(new Item("yy", 4, 44,0)); //was k->addItem


//             (N, E, S, W)
  a->setExits(f, b, d, c);
  b->setExits(NULL, NULL, NULL, a);
  c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, ai, i);
    e->setExits(NULL, NULL, NULL, d);
  f->setExits(NULL, g, a, h);
  g->setExits(NULL, NULL, NULL, f);
  h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    ai->setExits(d, NULL, start, NULL);
    start->setExits(ai, chr_b, NULL, chr_a);
    bridge->setExits(NULL, NULL, f, NULL);
    chr_a->setExits(NULL, start, dcr_a, NULL);
    chr_b->setExits(NULL, NULL, dcr_b, start);
    dcr_a->setExits(chr_a, NULL, NULL, e_room_a);
    dcr_b->setExits(chr_b, e_room_b, NULL, NULL);
    e_room_a->setExits(NULL, dcr_a, NULL, NULL);
    e_room_b->setExits(NULL, NULL, NULL, dcr_b);
    /*la->setExits(NULL, NULL, NULL, NULL);
    lb->setExits(NULL, NULL, NULL, NULL);
    lc->setExits(NULL, NULL, NULL, NULL);
    ld->setExits(NULL, NULL, NULL, NULL);
    le->setExits(NULL, NULL, NULL, NULL);
    lf->setExits(NULL, NULL, NULL, NULL);*/


    tmpMap[1]= a;
    tmpMap[2]= b;
    tmpMap[3]= c;
    tmpMap[4]= d;
    tmpMap[5]= e;
    tmpMap[6]= f;
    tmpMap[7]= g;
    tmpMap[8]= h;
    tmpMap[9]= i;
    tmpMap[10]= ai;
    tmpMap[11]= start;
    tmpMap[12]= bridge;
    tmpMap[13]= chr_a;
    tmpMap[14]= chr_b;

    currentRoom = start; // was k
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

// Generic string to QString
QString ZorkUL::genericStringsToQString(string str){
    return QString::QString::fromStdString(str);
}
int ZorkUL::returnNumberOfChallenges(){
     return currentChallenger->getNumOfChallenges();
}
QString ZorkUL:: returnRoom(){
     return genericStringsToQString(currentRoom->longDescription());
}
QString ZorkUL:: returnLive(){

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
                if(currentChallenger->getNumOfChallenges()>0){
                  roomInfo();
                }
                else
                {
              //      ~currentChallenger();
                    createChallenger(createChallengerID());
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
       // we see later what to do here
       // print somethin nice maybe?
    }
	else
	{
        //~currentRoom();
		currentRoom = nextRoom;
        // check challenges here if not finished previously
        //do nothing here otherwise
        //qDebug()<<currentChallenger->getNumOfChallenges();

        if(currentChallenger==NULL){
          // do nothing keep going here
          createChallenger(createChallengerID());
        }
        else
        {
            if(currentChallenger->getNumOfChallenges()>0){
               qDebug()<<"Test 2";
           }
            else{
                // ~currentChallenger();
                 createChallenger(createChallengerID());
            }
        }
	}
}
int ZorkUL::idRequest(){
    return currentChallenger->getChallengerID();
}

int ZorkUL::createChallengerID(){

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
    else if(tmp.compare("AI")==0){
       return 2;
    }
    else if(tmp.compare("z")==0){
       return 12;
    }
 }
