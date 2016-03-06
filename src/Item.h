#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:

	string description;
	string longDescription;
	int weightGrams;
	float value;
    bool weaponCheck;
    bool infoCheck;
    bool isReadable;
    bool isEncrypted;
    bool isWeapon;
    string information;

    bool isReadableInformation();
    bool isEncryptedInformation();

public:
    Item(string description, int inWeight, float inValue,int weapon );
    Item(string description);
    Item(string inInformation, int type, string descr);
    Item();
    void setInformation(string);
    string getShortDescription();
    string getLongDescription();

    void setDescription(string inDescription);

    int getWeight();

    void setWeight(int weightGrams);

    float getValue();
	void setValue(float value);

    int getKeyCheck();
    int setKeyCheck();

    bool getInfoCheck();
    void setInfoCheck(bool isInfo, int type);
    void setIsReadableInformation(bool readable);
    void setIsEncryptedInformation(bool encrypted);

    bool getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
