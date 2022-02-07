//
// Created by Jerry on 4/23/20.
//

#include "Friend.h"

//define constructors
Friend::Friend() //default constructor
{
    Name = "";
    Age = 0;
    PhoneNumber = "";
    HaveASignificantOther = false;
}
//constructor with name and phone number as parameters
Friend::Friend(string nm, string phoneNum)
{
    Name = nm;
    Age = 0;
    PhoneNumber = phoneNum;
    HaveASignificantOther = false;
}
//mutator functions
void Friend::setName(string nm)
{
    Name = nm;
}
void Friend::setAge(int ageNum)
{
    Age = ageNum;
}
void Friend::setPhone(string phoneNum)
{
    PhoneNumber = phoneNum;
}
void Friend::setSigOther(bool sigOther)
{
    HaveASignificantOther = sigOther;
}

//accessor functions
const string Friend::getName() const
{
    return Name;
}
const int Friend::getAge() const
{
    return Age;
}
const string Friend::getPhone() const
{
    return PhoneNumber;
}
const bool Friend::getSigOther() const
{
    return HaveASignificantOther;
}

//function to give total members in friend party
int Friend::NumRSVP(bool sigOther)
{
    if (HaveASignificantOther == false)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
