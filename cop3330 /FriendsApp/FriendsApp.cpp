#include <iostream>
#include <string>
#include "Friend.h"

using namespace std;

/* Name: Jerry Laplante
Date: 04/23/2020
Section: 0008
Assignment: Friends Program
Due Date: 04/24/2020
About this project: This program will list the members and total a reservation using
object oriented programming.
Assumptions: N/A
All work below was performed by Jerry Laplante */

void DisplayFriend(Friend fri); //function prototype to display data

int main() {
    cout << "Welcome to the Friends App Program!" << endl << endl; //Welcome user

    //create instances for three friends

    Friend fri1("Kristen Lee", "555-2021");
    fri1.setAge(45);

    Friend fri2 ("Joe Smith", "111-9999");
    fri2.setAge(55);
    fri2.setSigOther(true);

    Friend fri3 ("Tom Hanks", "111-8888");
    fri3.setAge(75);
    fri3.setSigOther(true);


    DisplayFriend(fri1); //call display function 3 times

    DisplayFriend(fri2);

    DisplayFriend(fri3);

    int total; //create variable to hold total number of people
    //logic to sum people in reservation
    total = (fri1.NumRSVP(fri1.getSigOther()) +
             fri2.NumRSVP(fri2.getSigOther()) +
             fri3.NumRSVP(fri3.getSigOther()));

    cout << "Total number coming to restaurant: " << total; //display total

return 0;
}

void DisplayFriend(Friend fri) //logic for display function
{
    cout << "Name: " << fri.getName() << endl;
    cout << "Phone Number: " << fri.getPhone() << endl;
    cout << "Age: " << fri.getAge() << endl;
    if (fri.getSigOther() == false)
    {
        cout << "Have Significant Other: " << "No" << endl;
    }
    else
        cout << "Have Significant Other: " << "Yes" << endl;
    cout << endl;
}