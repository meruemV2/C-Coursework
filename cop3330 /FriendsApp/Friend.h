//
// Created by Jerry on 4/23/20.
//

#ifndef FRIENDSAPP_FRIEND_H
#define FRIENDSAPP_FRIEND_H
#include <string>

using namespace std;
//define class called Friend
class Friend {

private: //set variables to private
    string Name;
    int Age;
    string PhoneNumber;
    bool HaveASignificantOther;

public: //set mutator, accessor, constructor, and other functions to public
    Friend();
    Friend (string nm, string phoneNum);

    //mutator functions
    void setName(string nm);
    void setAge(int ageNum);
    void setPhone(string phoneNum);
    void setSigOther(bool sigOther);

    //accessor functions
    const string getName() const;
    const int getAge() const;
    const string getPhone() const;
    const bool getSigOther() const;

    //function to get total number of people in one party
    int NumRSVP(bool sigOther);


};


#endif //FRIENDSAPP_FRIEND_H
