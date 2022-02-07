#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
//include necessary libraries

/*
Name: Jerry Laplante
Date: 05/13/2020
Assignment: Lottery Numbers Generator
About this project: This is a program to generate random lottery number
values and the odds of winning said lottery
*/

using namespace std;

void lotteryGenerator (int, int, int);
int getValidBalls (int &);
int getValidRange (int &);
int getValidTix (int &);
double factorial1 (int);
double factorial2 (int);
double factorial3 (int);
//function prototypes

int main() {

    int numBalls, numRange, numTix; // declare needed variables
    srand(time(0)); //pass current time to srand for initial seed of random numbers


    cout << "Welcome to the Lottery Generator Program!" << endl << endl; // welcome user


    cout << "Please enter the desired number of balls or numbers you wish to pick from." << endl;
    cout << "The number must be between 3 and 7..." << endl; //specify input

    cin >> numBalls;
    getValidBalls(numBalls); //call function to validate input

    cout << "Enter the largest number in the lottery..." << endl;
    cout << "The number must be between 45 and 70..." << endl; //specify input

    cin >> numRange;
    getValidRange(numRange); //call function to validate input

    cout << "Enter the desired number of tickets from 1 to 100..." << endl; //specify input

    cin >> numTix;
    getValidTix(numTix); //call function to validate input

    lotteryGenerator(numBalls, numRange, numTix); //call function to generate lottery odds and numbers

return 0;


}
int getValidBalls(int &numBalls) //input validation function with pass by reference parameter
{
    while ( numBalls < 3 || numBalls > 7 )
    {
        cout << "Please enter a valid ball number between 3 and 7..." << endl;
        cin >> numBalls;
    }
    return numBalls; //returns good input
}
int getValidRange(int &numRange) //input validation function with pass by reference parameter
{
    while ( numRange < 45 || numRange > 70)
    {
        cout << "Please enter a valid number between 45 and 70..." << endl;
        cin >> numRange;
    }
    return numRange; //returns good input
}
int getValidTix(int &numTix) //input validation function with pass by reference parameter
{
    while (numTix < 1 || numTix > 100) {
        cout << "Please enter a valid ticket number between 1 and 100..." << endl;
        cin >> numTix;
    }
    return numTix; //returns good input
}
double factorial1(int numRange) //factorial function for range using recursion
{
    if (numRange > 1)
        return numRange * factorial1(numRange - 1);
    else
    return 1;
}
double factorial2(int numBalls) //factorial function for balls using recursion
{
    if (numBalls > 1)
        return numBalls * factorial2(numBalls - 1);
    else
    return 1;
}
double factorial3(int n) //factorial function to be used in odds formula using recursion
{
    if (n > 1)
        return n * factorial3(n - 1);
    else
    return 1;
}



void lotteryGenerator (int numBalls, int numRange, int numTix) //logic and display function to generate lottery numbers
{
    cout << "You will select " << numBalls << " numbers" << endl << endl;

    cout << "The numbers will range from 1 to " << numRange << endl << endl;

    int n = numRange-numBalls; //variable used in odds function

    double odds; //declare double to hold large value of odds

    odds = ((factorial1(numRange)) / (factorial2(numBalls) * factorial3(n))); //odds logic

    cout << "The odds are 1 in " << setprecision(0) << fixed << odds << endl << endl << endl; //show odds

    cout << "YOUR LOTTERY SELECTIONS ARE:" << endl << endl;


    for (int j = 0; j < numTix; j++) //logic to display lottery numbers for each ticket
{
    int numbers[numBalls]; //declare array to hold numbers for each ticket

    for (int i = 0; i < numBalls; i++) //logic to loop through each number of tickets
    {
        bool notTaken; //bool variable to flag if number is taken
        int randNum; // variable to hold random number

        do{
            randNum = (rand() % numRange + 1); //logic to generate random numbers between range

            notTaken = true;
            for (int k = 0; k < i; k++) //logic to check if number is taken
                if (randNum == numbers[k]) {
                    notTaken = false;
                    break;
                }
        } while (!notTaken);

        numbers[i] = randNum; //add random number to array of numbers

        cout << numbers[i] << " "; //display numbers for each ticket
    }
    cout << endl;

}
}

