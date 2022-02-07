#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>//libraries needed

using namespace std;

/* Name: Jerry Laplante
Date: 04/08/2020
Section: 0008
Assignment: Lottery Numbers Program
Due Date: 04/08/2020
About this project: This is a menu driven program to show averages of winning
Lottery Numbers
Assumptions: None
All work below was performed by Jerry Laplante*/


void swap(int &, int &);
void displayMostCommon(vector<int>);
void displayLeastCommon(vector<int>);
void displayRegFrequency(vector<int>);
void displayPowerFrequency(vector<int>); //declare necessary function prototypes

int main() {

    ifstream inFile; //declare fstream types to process in file


    int num; //declare int to hold numbers as file processes through
    vector<int> numbers; //declare vector to hold numbers

    inFile.open("Lottery_Powerball_Winning_Numbers.txt"); //open file

    if (inFile)
    {
        while(inFile>>num) //read in file
            numbers.push_back(num);//store numbers in vector
        inFile.close(); // close file
    }


    cout << "Welcome to the Powerball Lottery Numbers Program!" << endl; // =welcome user to program
    cout << "Please select option (A-D) ..." << endl;

    char choice;

    cin >> choice; //take in user choice


    if (toupper(choice) == 'A') //choices with function calls
    {
        displayMostCommon(numbers);
    }

    else if (toupper(choice) == 'B' )
    {
        displayLeastCommon(numbers);
    }

   else if (toupper(choice) == 'C' )
    {
        displayRegFrequency(numbers);
    }

    else if (toupper(choice) == 'D' )
    {
        displayPowerFrequency(numbers);
    }
    else
    {
        cout << "Invalid option entered.." << endl; //trailing else statement for errors
    }


    return 0;
}

void swap(int &a, int &b) //swap function for sorting algorithm
{
    int temp = a;
    a = b;
    b = temp;
}

void displayMostCommon(vector<int> numbers) //function to display most common regular numbers
{
    vector<int> instance(69); //new vectors ro help with sorting logic
    vector<int> num(69);
    int size = 69;
    float total = 0;

    for( int i = 1; i <= size; i++) //initialize new vectors with total appearances and associated number
    {
        num[(i-1)] = i;
        int acc = 0;
        for (int count = 0; count < numbers.size(); count++)
        {
            if ( i == numbers[count] && ((count+1)%6) != 0 ) //dont count power number
            {
                acc = acc+1;
            }
        }
        instance[(i-1)] = acc;
        total = total + acc;
    }

    vector <float> averages(69); //new vector to hold averages

    for (int i = 0; i < size; i++)
    {
        averages[i] = (instance[i]/total);
    }


    int maxElement;
    int index;

    for ( maxElement = (size - 1); maxElement > 0; maxElement--) //sort parallel arrays by averages
    {
        for (index = 0; index < maxElement; index++)
        {
            if (averages[index] > averages[index + 1])
            {
                swap(averages[index], averages[index + 1]);
                swap(num[index], num[index + 1]);
            }
        }
    }

    for (int i = 68; i > 58; i--) // output number and its average
    {
        cout << setw(4) << setprecision(4) << fixed << num[i] << ": " << (averages[i]*100) << "%" << endl;
    }
}

void displayLeastCommon(vector<int> numbers)
{
    vector<int> instance(69); //new vectors for sorting
    vector<int> num(69);
    int size = 69;
    float total = 0;

    for( int i = 1; i <= size; i++) //initialize new vectors with instances and numbers
    {
        num[(i-1)] = i;
        int acc = 0;
        for (int count = 0; count < numbers.size(); count++)
        {
            if ( i == numbers[count] )
            {
                acc = acc+1;
            }
        }
        instance[(i-1)] = acc;
        total = total + acc;
    }

    vector <float> averages(69);

    for (int i = 0; i < size; i++) //hold averages
    {
        averages[i] = (instance[i]/total);
    }


    int maxElement;
    int index;

    for ( maxElement = (size - 1); maxElement > 0; maxElement--) //sort parallel arrays by averages
    {
        for (index = 0; index < maxElement; index++)
        {
            if (averages[index] > averages[index + 1])
            {
                swap(averages[index], averages[index + 1]);
                swap(num[index], num[index + 1]);
            }
        }
    }

    for (int i = 0; i < 10; i++) // output number and average
    {
        cout << setw(4) << setprecision(4) << fixed << num[i] << ": " << (averages[i]*100) << "%" << endl;
    }
}

void displayRegFrequency(vector<int> numbers)
{
    vector<int> instance(69); //new vectors to help with logic
    vector<int> num(69);
    int size = 69;
    float total = 0;

    for( int i = 1; i <= size; i++) //initialize with numbers and frequency
    {
        num[(i-1)] = i;
        int acc = 0;
        for (int count = 0; count < numbers.size(); count++)
        {
            if ( i == numbers[count] && ((count+1)%6) != 0 )
            {
                acc = acc+1;
            }
        }
        instance[(i-1)] = acc;
        total = total + acc;
    }

    vector <float> averages(69); //frequency to percentages

    for (int i = 0; i < size; i++)
    {
        averages[i] = (instance[i]/total);
    }

    for (int i = 0; i < 69; i++) // output all numbers and averages
    {
        cout << setw(4) << setprecision(2) << fixed << num[i] << ": " << (averages[i]*100) << "%" << endl;
    }
}

void displayPowerFrequency(vector<int> numbers)
{
    vector<int> instance(26); //new vectors to hold powerball numbers
    vector<int> num(26);
    int size = 26;
    float total = 0;

    for( int i = 1; i <= size; i++) //initialize vectors
    {
        num[(i-1)] = i;
        int acc = 0;
        for (int count = 0; count < numbers.size(); count++)
        {
            if ( i == numbers[count] && (((count+1)%6)== 0) ) //only count 6th numbers
            {
                acc = acc+1;
            }
        }
        instance[(i-1)] = acc;
        total = total + acc;
    }

    vector <float> averages(26); //hold averages

    for (int i = 0; i < size; i++)
    {
        averages[i] = (instance[i]/total);
    }

    for (int i = 0; i < 26; i++) // output powerball numbers and average
    {
        cout << setw(4) << setprecision(2) << fixed << num[i] << ": " << (averages[i]*100) << "%" << endl;
    }
}