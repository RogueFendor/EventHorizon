#include "Room.h"

// Constuctor
Room::Room(string description) {
	this->description = description;
}

/*
    This method set the exits in each Room
    assciative array 4 index keys values are pointers to rooms

*/

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

// returns the room short description
string Room::shortDescription() {
	return description;
}
// return the lon decription
string Room::longDescription() {

    return "room = " + description + ".\n" + displayItem() +exitString();
}

/*
this Method returns the available exits correponding to the current room
*/
string Room::exitString() {
	string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

/*
    This method allow the user to change the room!
    a map object mapping a direction string to a room object.
    each instantiated room has a map object containing the exit string as
    key pointing to a possible room as exit point.

*/

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
        return NULL;
    // if exits.end() was returned, there's no room in that direction.
    return next->second;
    // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
  }

/*
this Method adds a new item to a room
new item object is instantiated and pushed into the Item  vector
*/

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}
/*
 this iterates through the item vector and returns a item description
*/

string Room::getItemDetails(int id){
     string tempString = "item Details:\n\n ";
        tempString += tempString + itemsInRoom[id -1].getLongDescription();
        return tempString;

}

/*
  this Method return a more detailed item description

*/

string Room::displayItem() {
    string tempString = "Available Items:\nItem name = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = 0;
        for (int n = sizeItems; n > 0; n--) {
           tempString = tempString + itemsInRoom[x].getShortDescription()+exitString();
            x++;
            }
        }
    return tempString;
}

// return the number of current items in the item vector
int Room::numberOfItems() {
    return itemsInRoom.size();
}

// check has room an item
int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

