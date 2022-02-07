//
// Created by Jerry on 5/25/20.
//

#include "date.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
    format = 'D';

}

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
    format = 'D';


    if ((year < 1583) && (month < 10))
    {
        cout << "Error: Invalid year input..." << endl;
        month = 1;
        day = 1;
        year = 2000;
        format = 'D';
    }
    if ((month < 1) || (month > 12 ))
    {
        cout << "Error: Invalid month input..." << endl;
        month = 1;
        day = 1;
        year = 2000;
        format = 'D';
    }

    if ((month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10)||(month == 12))
    {
        if ((day < 1) || (day > 31))
        {
            cout << "Error: Invalid day input..." << endl;
            month = 1;
            day = 1;
            year = 2000;
            format = 'D';
        }
    }
    if ((month == 4)||(month == 6)|| (month == 9)||(month == 11))
    {
        if ((day < 1)|| (day > 30))
        {
            cout << "Error: Invalid day input..." << endl;
            month = 1;
            day = 1;
            year = 2000;
            format = 'D';
        }
    }
    if (month == 2)
    {
        if ((year % 4) == 0)
        {
            if ((year % 100) == 0)
            {
                if ((year % 400) == 0)
                {
                    if ((day < 1) || (day > 29))
                    {
                        cout << "Error: Invalid day input..." << endl;
                        month = 1;
                        day = 1;
                        year = 2000;
                        format = 'D';
                    }
                }
                else if ((day < 1) || (day > 28))
                {
                    cout << "Error: Invalid day input..." << endl;
                    month = 1;
                    day = 1;
                    year = 2000;
                    format = 'D';
                }
            }
            else if ((day < 1) || (day > 29))
            {
                cout << "Error: Invalid day input..." << endl;
                month = 1;
                day = 1;
                year = 2000;
                format = 'D';
            }
        }
        else if ((day < 1) || (day > 28))
        {
            cout << "Error: Invalid day input..." << endl;
            month = 1;
            day = 1;
            year = 2000;
            format = 'D';
        }
    }
}

void Date::Input()
// * Function Name:  Input
// * Description:  Prompts, accepts and validates user input to change date
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    cout << "Please enter a date in month/day/year format using integer values" << endl << endl;

    cout << "Enter month value from 1 to 12..." << endl;
    cin >> month;

    cout << "Enter day..." << endl;
    cin >> day;

    cout << "Enter year..." << endl;
    cin >> year;

    while ((year < 1583) && (month < 10))
    {
        cout << "Error: Invalid year input..." << endl;
        month = 1;
        day = 1;
        year = 2000;
        format = 'D';
    }

    while ((month < 1) || (month > 12))
    {
        cout << "Error: Invalid date. Try again: " << endl;
        cout << "Enter month value from 1 to 12..." << endl;
        cin >> month;

        cout << "Enter day..." << endl;
        cin >> day;

        cout << "Enter year..." << endl;
        cin >> year;
    }
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) ||
        (month == 12))
    {
        while ((day < 1) || (day > 31))
        {
            cout << "Error: Invalid date. Try again: " << endl;
            cout << "Enter month value from 1 to 12..." << endl;
            cin >> month;

            cout << "Enter day..." << endl;
            cin >> day;

            cout << "Enter year..." << endl;
            cin >> year;
        }
    }
    if ((month == 4)||(month == 6)|| (month == 9)||(month == 11))
    {
        while ((day < 1) || (day > 30))
        {
            cout << "Error: Invalid date. Try again: " << endl;
            cout << "Enter month value from 1 to 12..." << endl;
            cin >> month;

            cout << "Enter day..." << endl;
            cin >> day;

            cout << "Enter year..." << endl;
            cin >> year;
        }
    }
    if (month == 2)
    {
        if ((year % 4) == 0)
        {
            if ((year % 100) == 0)
            {
                if ((year % 400) == 0)
                {
                    while ((day < 1) || (day > 29))
                    {
                        cout << "Error: Invalid date. Try again: " << endl;
                        cout << "Enter month value from 1 to 12..." << endl;
                        cin >> month;

                        cout << "Enter day..." << endl;
                        cin >> day;

                        cout << "Enter year..." << endl;
                        cin >> year;
                    }
                }
                else while ((day < 1) || (day > 28))
                {
                    cout << "Error: Invalid date. Try again: " << endl;
                    cout << "Enter month value from 1 to 12..." << endl;
                    cin >> month;

                    cout << "Enter day..." << endl;
                    cin >> day;

                    cout << "Enter year..." << endl;
                    cin >> year;
                }
            }
            else while ((day < 1) || (day > 29))
            {
                cout << "Error: Invalid date. Try again: " << endl;
                cout << "Enter month value from 1 to 12..." << endl;
                cin >> month;

                cout << "Enter day..." << endl;
                cin >> day;

                cout << "Enter year..." << endl;
                cin >> year;
            }
        }
        else while ((day < 1) || (day > 28))
        {
            cout << "Error: Invalid date. Try again: " << endl;
            cout << "Enter month value from 1 to 12..." << endl;
            cin >> month;

            cout << "Enter day..." << endl;
            cin >> day;

            cout << "Enter year..." << endl;
            cin >> year;
        }
    }
}
void Date::Show()
// * Function Name:  Show
// * Description:  display date class data based on current format
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    if (format == 'D') {
        cout << month << "/" << day << "/" << year << endl;
    }

    if (format == 'T') {
        cout << setprecision(2) << month << "/" << day << "/" << (year % 100) << endl;
    }

    if (format == 'L') {
        switch (month) {
            case 1:
                cout << "Jan" << " " << day << ", " << year << endl;
                break;
            case 2:
                cout << "Feb" << " " << day << ", " << year << endl;
                break;
            case 3:
                cout << "Mar" << " " << day << ", " << year << endl;
                break;
            case 4:
                cout << "Apr" << " " << day << ", " << year << endl;
                break;
            case 5:
                cout << "May" << " " << day << ", " << year << endl;
                break;
            case 6:
                cout << "June" << " " << day << ", " << year << endl;
                break;
            case 7:
                cout << "July" << " " << day << ", " << year << endl;
                break;
            case 8:
                cout << "Aug" << " " << day << ", " << year << endl;
                break;
            case 9:
                cout << "Sept" << " " << day << ", " << year << endl;
                break;
            case 10:
                cout << "Oct" << " " << day << ", " << year << endl;
                break;
            case 11:
                cout << "Nov" << " " << day << ", " << year << endl;
                break;
            case 12:
                cout << "Dec" << " " << day << ", " << year << endl;
                break;
        }

    }

    if (format == 'J')
    {
        if ((year % 4) == 0)
        {
            if ((year % 100) == 0)
            {
                if ((year % 400) == 0)
                {
                    day = (day + 1);
                }
            }
            day = (day + 1);
        }
        switch (month)
        {
            case 1:
                cout << day << ", " << year << endl;
                break;
            case 2:
                cout << (day + 31) << ", " << year << endl;
                break;
            case 3:
                cout << (day + 59) << ", " << year << endl;
                break;
            case 4:
                cout << (day + 90) << ", " << year << endl;
                break;
            case 5:
                cout << (day + 120) << ", " << year << endl;
                break;
            case 6:
                cout << (day + 151) << ", " << year << endl;
                break;
            case 7:
                cout << (day + 181) << ", " << year << endl;
                break;
            case 8:
                cout << (day + 212) << ", " << year << endl;
                break;
            case 9:
                cout << (day + 243) << ", " << year << endl;
                break;
            case 10:
                cout << (day + 273) << ", " << year << endl;
                break;
            case 11:
                cout << (day + 304) << ", " << year << endl;
                break;
            case 12:
                cout << (day + 334) << ", " << year << endl;
                break;
        }
    }
}

bool Date::Set(int m, int d, int y)
// * Function Name:  Set
// * Description: Sets Date class according to accepted user parameters or
// * outputs error if parameters are invalid
// * Parameter Description:   int m to hold month, int d to hold day, int y to hold year
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
   int tempmonth = m;
   int tempday = d;
   int tempyear = y;
   true;

    if ((tempyear < 1583) && (tempmonth < 10))
    {
        cout << "Error: Invalid year input..." << endl;
        return false;
    }
    else if ((tempmonth < 1) || (tempmonth > 12 ))
    {
        cout << "Error: Invalid month input..." << endl;
        return false;

    }

    else if ((tempmonth == 1)||(tempmonth == 3)||(tempmonth == 5)||(tempmonth == 7)||(tempmonth == 8)||(tempmonth == 10)||(tempmonth == 12))
    {
        if ((tempday < 1) || (tempday > 31))
        {
            cout << "Error: Invalid day input..." << endl;
            return false;

        }
    }
    else if ((tempmonth == 4)||(tempmonth == 6)|| (tempmonth == 9)||(tempmonth == 11))
    {
        if ((tempday < 1) || (tempday > 30))
        {
            cout << "Error: Invalid day input..." << endl;
            return false;

        }
    }
    else if (tempmonth == 2)
    {
        if ((tempyear % 4) == 0)
        {
            if ((tempyear % 100) == 0)
            {
                if ((tempyear % 400) == 0)
                {
                    if ((tempday < 1) || (tempday > 29))
                    {
                        cout << "Error: Invalid day input..." << endl;
                        return false;
                    }
                }
                else if ((tempday < 1) || (tempday > 28))
                {
                    cout << "Error: Invalid day input..." << endl;
                    return false;
                }
            }
            else if ((tempday < 1) || (tempday > 29))
            {
                cout << "Error: Invalid day input..." << endl;
                return false;
            }
        }
        else if ((tempday < 1) || (tempday > 28))
        {
            cout << "Error: Invalid day input..." << endl;
            return false;
        }
    }
    else if (true);
    {
        month = m;
        day = d;
        year = y;
        cout << "Date change successful." << endl;
        return true;
    }
}

int Date::GetMonth() const
// * Function Name:  Get_Month
// * Description:  returns month in Date class to user
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    return month;
}

int Date::GetDay() const
// * Function Name:  Get_Day
// * Description:  returns day in Date class to user
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    return day;
}

int Date::GetYear() const
// * Function Name:  Get_Year
// * Description:  returns year in Date class to user
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    return year;
}

bool Date::SetFormat(char f)
// * Function Name:  Set_Format
// * Description: changes format setting based on correct user inputted paramter
// * Parameter Description: char f holds value to be compared and altered if needed
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    false;

    if ( toupper(f) == 'D')
    {
        format = 'D';
        cout << "Format change successful." << endl;
        true;
    }
    else if ( toupper(f) == 'T')
    {
        format = 'T';
        cout << "Format change successful." << endl;
        true;
    }
    else if ( toupper(f) == 'L')
    {
        format = 'L';
        cout << "Format change successful." << endl;
        true;
    }
    else if ( toupper(f) == 'J')
    {
        format = 'J';
        cout << "Format change successful." << endl;
        true;
    }
    else
    {
        cout << "Error: Invalid format. Try again..." << endl;
        false;
    }

}

void Date::Increment(int numdays)
// * Function Name:  Increment
// * Description:  increments the date by user inputted parameter
// * Parameter Description: int numdays to hold value of days that have passed
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    int Days_in_Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (int i = 0 ;i < numdays; i++)
    {
        if (((year % 4) == 0) || ((year % 400) == 0))
        {
            Days_in_Month[1] = 29;
        }
        day++;
        if (day > Days_in_Month[month-1] )
        {
            day = 1;
            month++;
            if (month==13)
            {
                month = 1;
                year++;
            }
        }
    }
}

int Date::Compare(const Date& d)
// * Function Name:  Compare
// * Description:  returns either 1, -1, or 0 based on whether calling object
// * or parameter object is first chronologically
// * Parameter Description:   N/A
// * Date:  05/29/2020
// * Author: Jerry Laplante
// * References: N/A
{
    if (year > d.year)
    {
        return 1;
    }
    else if (year < d.year)
    {
        return -1;
    }
    else if (year == d.year)
    {
        if (month > d.month)
        {
            return 1;
        }
        else if (month < d.month)
        {
            return -1;
        }
        else if (month == d.month)
        {
            if (day > d.day)
            {
                return 1;
            }
            else if (day < d.day)
            {
                return -1;
            }
            else if (day == d.day)
            {
                return 0;
            }
        }
    }

}