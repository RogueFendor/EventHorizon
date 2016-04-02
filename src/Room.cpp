#include "Room.h"
#include<QDebug>
// Constuctor
Room::Room(string description) {
	this->description = description;
}

/*Room
    This method set the exits in each Room
    assciative array 4 index keys values are pointers to rooms
Room
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


    return  "<font color='red'>Room: "+ description +"<br/>" + displayItem() + exitString()+"</font>";
}

/*
this Method returns the available exits correponding to the current room
*/
string Room::exitString() {
    string returnString = "<br><b>exits:</b><br/>";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += i->first +"<br/>";	// access the "first" element of the pair (direction as a string)
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
     string tempString = "<br/><b>item Details:</b><br/>";
        tempString += tempString + itemsInRoom[id -1].getLongDescription();
        return tempString;

}

/*
  this Method return a more detailed item description

*/

string Room::displayItem() {
    //string messageString = "<b>Available Items:<b><br/>Item name: ";
    string messageString = "<b>Available Items:";
    string itemString = "";

    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        messageString = "<b>No items in room!<b>";
        }
    else if (itemsInRoom.size() > 0) {
       int x = 0;
       //itemString = "";
        for (int n = sizeItems; n > 0; n--) {
            //itemString +="<br/>"+ itemString + itemsInRoom[x].getShortDescription();
            itemString +="<br/>"+ itemsInRoom[x].getShortDescription();
            x++;
            }
        }
    return messageString+=itemString + "<br>";
}

// return the number of current items in the item vector
Item Room::getConcreteItem(int i){
    return itemsInRoom[i];
}
string Room::populateComboBox(){

    string messageString = "Available Items:";
    string itemString = "";

    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        messageString = "No Available Items";
        }
    else if (itemsInRoom.size() > 0) {
       int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            itemString +=","+ itemsInRoom[x].getShortDescription();
            x++;
            }
        }
    return messageString+=itemString;
}
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

