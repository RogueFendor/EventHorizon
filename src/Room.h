#ifndef ROOM_H_
#define ROOM_H_
#include <map>
#include <string>
#include <vector>
#include "Item.h"
#include <QString>
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;

public:
    string populateComboBox();
    QString image;
    int numberOfItems();
	Room(string description);
    ~Room();
    Room *nextRoom(string direction);
    void setImage(QString n);
    QString getImage();
	void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
	string longDescription();
    Item getConcreteItem(int i);
    void addItem(Item *inItem);
    string displayItem();
    string getItemDetails(int id);
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    bool roomExists(string room);
};

#endif
