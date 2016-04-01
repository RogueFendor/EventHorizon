#include "Item.h"
#include<sstream>

Item::Item(){

}

Item::Item(string inDescription)
{
    description = inDescription;
}
bool Item::operator==(const Item& d)
 {


    if(description.compare(d.description)!=0){
        cout<<"Iam in here\n FASLE";
        cout<<"\ndescription LHS "<<description<<" ";
        cout<<"\ndescription RHS "<<d.description<<" ";
        cout<<"\n";
        return false;
    }
    else{
        cout<<"Iam in here\n TRUE";
        cout<<"\ndescription LHS "<<description<<" ";
        cout<<"\ndescription RHS "<<d.description<<" ";
        cout<<"\n";
        return false;
    }
 }
Item::Item (string inDescription, int inWeightGrams, float inValue, int weapon) {
	description = inDescription;
	setWeight(inWeightGrams);
	value = inValue;
    setWeaponCheck(weapon);
}

Item::Item(string inInformation, int type, string descr ){
    setInformation(inInformation);
    setDescription(descr);
    setInfoCheck(true, type);
}

void Item::setDescription(string inDescription) {
    description = inDescription;
}
void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weightGrams = inWeightGrams;
}
int Item::getWeight(){
    if(weightGrams == NULL || weightGrams ==0){
        return 0;
    }
    else{
        return weightGrams;
    }
}
void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}
float Item::getValue(){
    if(value == NULL || value ==0)
        return 0;
    else
        return value;
}
void Item::setInfoCheck(bool setIsInfo, int type){
    infoCheck=true;
    switch (type) {
    case 1:
        setIsReadableInformation(true);
        break;
    case 2:
        setIsEncryptedInformation(true);
        break;
    }
}

bool Item::getInfoCheck(){
    return infoCheck;
}
bool Item::isReadableInformation(){
    return isReadable;
}
bool Item::isEncryptedInformation(){
    return isReadable;
}
void Item::setIsReadableInformation(bool readable){
   isReadable = readable;
}
void Item::setIsEncryptedInformation(bool encrypted){
    isEncrypted = encrypted;
}
void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        isWeapon=false;
    else
        isWeapon=true;
}
bool Item::getWeaponCheck(){
    return isWeapon;
}
string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{

    stringstream item;
           item << "Item type:" << getShortDescription();
           item << "<br/>Is weapon: " << getWeaponCheck();
           item << "<br/>Is Readable: " << isReadableInformation();
           item << "<br/>Is Encrypted: " << isEncryptedInformation();
           item << "<br/>Weight: "<< getWeight();
           item << "<br/>Value: "<<  getValue();
           return item.str();
}
void Item::setInformation(string info ){
    information = info;
}
