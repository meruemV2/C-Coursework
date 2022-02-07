#include <iostream>
#include "date.h"
using namespace std;

// *******************************************************************************
// * Name: main *
// * Class: COP3330 *
// * Description: Test driver for the Date class, Assignment #2, COP3330. *
// * Tests to see if all of the methods have been declared in *
// * accordance with the specifications AND if the files have *
// * named properly. NOTE: This drive does not do a complete. *
// * test of your class. You should modify it to perform more *
// *. extensive testing. *
// * Author: Dr. David A. Gaitros *
// * Date: September 12, 2019 *
// * Copyright: This file is for use by students at Florida State University *
// * for the COP3330 course. *
// *******************************************************************************

int main(void)
{ bool status=false;
    int comparestatus=0;

    Date date1; // Test Default constructor
    Date date2(2,29,2000); // Test 3 param constructor with valid date
    Date date3(15,15,1500); // Test 3 param constructor with invalid date
    status=date3.Set(2,18,1955); // Test Set method
    status=date2.SetFormat('T'); // Test SetFormat method
    date2.Show(); // Test Show method
    date2.Input(); // Test the Input method
// *******************************************************************************
// * Test the GetMonth, GetDay, GetYear methods *
// *******************************************************************************

    cout << date2.GetMonth()<<'/'<<date2.GetDay()<<'/'<<date2.GetYear()<<endl;
    date1.Increment(); // Test Increment with no parameters
    date1.Increment(); // Test Increment with one parameter
    comparestatus=date1.Compare(date2); // Test Compare method
    return 0;
}

