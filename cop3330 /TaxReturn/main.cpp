#include <iostream>


using namespace std;

/* Name: Jerry Laplante
Date: 1/24/2020
Section: 0008
Assignment: Do I Need to File a Tax Return
Due Date: 1/26/2020
About this project: This program helps determine whether or not the
user needs to file a tax return.
Assumptions: None
All work below was performed by Jerry Laplante */

int main() {

    char a;     // Declare variable used to store user response.

    cout << "Unsure if you need to file an income tax? \n";
    cout << "This program should help! \n \n";
    //Welcome user to program.

    cout << "Are you single (Not Married) ?" << endl;     //Ask user to input information necessary for program.
    cout << "Enter the letter Y for yes or N for no..." << endl;     //Specify inputs accepted.

    cin >> a;  //Store input into variable.

    if ( a == 'y' || a == 'Y') //Test user input and choose path if correct.
    {
        cout << "Are you under 65 years of age?" << endl;    //Asks user for more relevant information.
        cout << "Enter the letter Y for yes or N for no..." << endl;   //Specify inputs accepted.

        cin >> a; //Store input into variable.

        if ( a == 'y' || a == 'Y') //Test user input and choose path if correct.
        {
            cout << "Is your gross income less than $8450?" << endl; //Asks user for more relevant information.
            cout << "Enter the letter Y for yes or N for no..." << endl;  // Specify inputs accepted.

            cin >> a; // Store input into variable.

            if ( a == 'y' || a == 'Y')  //Test user input and choose path if correct.
            {
                cout << "You do not have to file an income tax return." << endl;  //End of path
            }
            else if ( a == 'n' || a == 'N')  //Test user input and choose path if correct.
            {
                cout << "You have to file an income tax return." << endl;   //End of path
            }
            else // Input validation
            {
                cout << "Error: invalid input. \n \n";
                cout << "Please restart program with valid inputs....";
                //Error message if input invalid
            }
        }
        else if ( a == 'n' || a == 'N')  //Test user input and choose path if correct.
        {
            cout << "Is your gross income less than $9700?" << endl;  //Asks user for more relevant information.
            cout << "Enter the letter Y for yes or N for no..." << endl; // Specify inputs accepted.

            cin >> a; //Store input into variable.

            if ( a == 'y' || a == 'Y')  //Test user input and choose path if correct.
            {
                cout << "You do not have to file an income tax return." << endl; //End of path
            }
            else if ( a == 'n' || a == 'N')  //Test user input and choose path if correct.
            {
                cout << "You have to file an income tax return." << endl; //End of path
            }
            else    // Input validation
            {
                cout << "Error: invalid input. \n \n";
                cout << "Please restart program with valid inputs...";
                //Error message if input invalid
            }

        }
        else    // Input validation
        {
            cout << "Error: invalid input. \n \n";
            cout << "Please restart program with valid inputs...";
            //Error message if input invalid
        }

    }
    else if ( a == 'n' || a == 'N')  //Test user input and choose path if correct.
    {
        cout << "Sorry, this program is only for singles. \n \n ";
        cout << "Goodbye.";   //End of path
    }
    else    // Input validation
    {
        cout << "Error: invalid input. \n \n";
        cout << "Please restart program with valid inputs...";
        //Error message if input invalid
    }

    return 0;
}
