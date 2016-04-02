#include <iostream>
#include<ctime>
#include<cstdlib>
#include <map>
#include "Character.h"

// nice little lib for string streaming
#include <sstream>
#include "ZorkUL.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
//#include <algorithm>


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

    currentPlayer =new MainCharacter(1);
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
    gameStat =false;
    challengerExists =false;
}
// instantiate Challenger
void ZorkUL::createChallenger( int id){

    currentChallenger =new Challenger(id);
    currentChallenger->setChallengerID(id);
    setChallengerExists(true);
    setChallengerNeverExisted();

}
/*
Method to create all rooms
and adding items into them
*/
void ZorkUL::setChallengerExists(bool n){
    challengerExists = n;
}
bool ZorkUL::getChallengerExists(){
    return challengerExists;
}
void ZorkUL::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *ai, *start,
         *bridge, *chr_a, *chr_b, *dcr_a, *dcr_b, *e_room_a, *e_room_b,
         *la, *lb, *lc, *ld, *le, *lf;

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
    la = new Room("la");
    lb = new Room("lb");
    lc = new Room("lc");
    ld = new Room("ld");
    le = new Room("le");
    lf = new Room("lf");

    a->addItem(new Item("Dog"));
    a->addItem(new Item("Cat"));
    a->addItem(new Item("Bat"));
    //a->addItem(new Item("x", 1,"Dog"));
    //a->addItem(new Item("y", 2,"Cat"));
    e_room_a->addItem(new Item("Mushroom"));
    e_room_b->addItem(new Item("Clock"));
    la->addItem(new Item("Ham Sandwich"));
    la->addItem(new Item("Book - Guide to C++"));
    la->addItem(new Item("Coffee Cup"));
    la->addItem(new Item("Calendar"));
    lb->addItem(new Item("Foot"));
    lb->addItem(new Item("Nothing"));
    lb->addItem(new Item("Fork"));
    lb->addItem(new Item("Football"));
    lc->addItem(new Item("Candle"));
    lc->addItem(new Item("Small Bucket"));
    lc->addItem(new Item("Globe"));
    lc->addItem(new Item("Ant Farm"));
    ld->addItem(new Item("Bottle"));
    ld->addItem(new Item("Laptop"));
    ld->addItem(new Item("Frog"));
    ld->addItem(new Item("Model Spacecraft"));
    le->addItem(new Item("Edible Seaweed"));
    le->addItem(new Item("Map"));
    le->addItem(new Item("Engine Manual"));
    le->addItem(new Item("Hard Disk"));
    lf->addItem(new Item("Onion"));
    lf->addItem(new Item("Spacesuit"));
    lf->addItem(new Item("Meteorite"));
    lf->addItem(new Item("Photograph"));

    //start->addItem(new Item("yy", 4, 44,0)); //was k->addItem


    //             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(g, NULL, e, NULL);
    c->setExits(h, NULL, i, NULL);
    d->setExits(NULL, e, ai, i);
    e->setExits(b, NULL, NULL, d);
    f->setExits(NULL, g, NULL, h);
    g->setExits(NULL, NULL, b, f);
    h->setExits(NULL, f, c, NULL);
    i->setExits(c, d, NULL, NULL);
    ai->setExits(d, NULL, start, NULL);
    start->setExits(ai, chr_b, lc, chr_a);
    bridge->setExits(NULL, NULL, f, NULL);
    chr_a->setExits(NULL, start, dcr_a, NULL);
    chr_b->setExits(NULL, NULL, dcr_b, start);
    dcr_a->setExits(chr_a, NULL, NULL, e_room_a);
    dcr_b->setExits(chr_b, e_room_b, NULL, NULL);
    e_room_a->setExits(NULL, dcr_a, NULL, NULL);
    e_room_b->setExits(NULL, NULL, NULL, dcr_b);
    la->setExits(lb, ld, NULL, NULL);
    lb->setExits(lc, le, la, NULL);
    lc->setExits(start, lf, lb, NULL);
    ld->setExits(le, NULL, NULL, la);
    le->setExits(lf, NULL, lb, ld);
    lf->setExits(NULL, NULL, le, lc);


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
    tmpMap[15]= dcr_a;
    tmpMap[16]= dcr_b;
    tmpMap[17]= e_room_a;
    tmpMap[18]= e_room_b;
    //is it neccessary to add rooms la to lf here alos?

    currentRoom = start; // was k

    /**

    a->setExits(f, b, d, c);
    b->setExits(g, NULL, e, a);
    c->setExits(h, a, i, NULL);
    d->setExits(a, e, ai, i);
    e->setExits(b, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, b, f);
    h->setExits(NULL, f, c, NULL);
    i->setExits(c, d, NULL, NULL);
    ai->setExits(d, NULL, start, NULL);
    start->setExits(ai, chr_b, lc, chr_a);
    bridge->setExits(NULL, NULL, f, NULL);
    chr_a->setExits(NULL, start, dcr_a, NULL);
    chr_b->setExits(NULL, NULL, dcr_b, start);
    dcr_a->setExits(chr_a, NULL, NULL, e_room_a);
    dcr_b->setExits(chr_b, e_room_b, NULL, NULL);
    e_room_a->setExits(NULL, dcr_a, NULL, NULL);
    e_room_b->setExits(NULL, NULL, NULL, dcr_b);
    la->setExits(lb, ld, NULL, NULL);
    lb->setExits(lc, le, la, NULL);
    lc->setExits(start, lf, lb, NULL);
    ld->setExits(le, NULL, NULL, la);
    le->setExits(lf, NULL, lb, ld);
    lf->setExits(NULL, NULL, le, lc);


    */




}

/*
 *  Main play routine.  Loops until end of play.
 */
// Wellcome :-)
int ZorkUL::getUnlockA(){

    return unlockACounter;
}

void ZorkUL::setUnlockA(){

    unlockACounter++;
}
void ZorkUL::opeRoomA(){

    tmpMap.at(2)->setExits(tmpMap.at(7), NULL, tmpMap.at(5), tmpMap.at(1));
    tmpMap.at(3)->setExits(tmpMap.at(8), tmpMap.at(1), tmpMap.at(9), NULL);
    tmpMap.at(4)->setExits(tmpMap.at(1), tmpMap.at(5), tmpMap.at(10), tmpMap.at(9));
    tmpMap.at(6)->setExits(NULL, tmpMap.at(7), tmpMap.at(1), tmpMap.at(8));
}
void ZorkUL::setChallengerNeverExisted(){
    compMap.push_back(currentChallenger->getChallengerID());
}

bool ZorkUL::ChallengerNeverExisted(int challId){
    if(find(compMap.begin(), compMap.end(), challId ) != compMap.end()){
        // it found challenger name in list
        return false;
    }
    else{
        // did not find challenger name in list
        qDebug()<<challId<<"TRUE";
        return true;
    }

}
void ZorkUL::setGameStat(bool gS){
    gameStat = gS;
}
bool ZorkUL::getGameStat(){
    return gameStat;
}
QString ZorkUL::printWelcome() {
     QString info =QString("<font color='red'><b>Wellcome to EventHorizon<b><br/>Captain Rogers We are happy to see you!</b></font>");
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
int ZorkUL::returnNumberOfChallenges(){
     return currentChallenger->getNumOfChallenges();
}
QString ZorkUL:: returnRoom(){
     return genericStringsToQString(currentRoom->longDescription());
}
QString ZorkUL:: returnLive(){

}

void ZorkUL::teleport(){   
        currentRoom = tmpMap.at(12);
        createChallenger(createChallengerID());
        bool n = true;
        setGameStat(n);

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
        setGameStat(false);
    }
	else
	{
        //~currentRoom();
		currentRoom = nextRoom;
        // check challenges here if not finished previously
        //do nothing here otherwise
        //qDebug()<<currentChallenger->getNumOfChallenges();
        if(getChallengerExists()==false){
                if(createChallengerID()<40 ){
                    if(ChallengerNeverExisted(createChallengerID())==true){
                       createChallenger(createChallengerID());

                       bool n = true;
                       setGameStat(n);
                       createChallenger(createChallengerID());
                    }
                    else{
                       bool n = false;
                       setGameStat(n);
                    }
                }
        }
        else{
           if(currentChallenger->getNumOfChallenges()>0){

               qDebug()<<"Test 1 here changing value";
               qDebug()<<currentChallenger->getNumOfChallenges();
               bool n = false;
               setGameStat(n);
           }
            else{
                 if(ChallengerNeverExisted(createChallengerID())==true){
                    qDebug()<<"Test 2 here changing value";
                    bool n = true;
                    setGameStat(n);
                    createChallenger(createChallengerID());
                 }
                 else{
                    bool n = false;
                    setGameStat(n);
                 }

            }
        }
   }
}
int ZorkUL::idRequest(){
    return currentChallenger->getChallengerID();
}

int ZorkUL::createChallengerID(){

    string tmp = currentRoom->shortDescription();
    qDebug()<<this->genericStringsToQString(tmp);
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
    else if(tmp.compare("BRIDGE")==0){
       return 12;
    }
    else{
        return 42;
    }
 }
