//
// Created by Jerry on 5/25/20.
//

#ifndef DATE_DATE_H
#define DATE_DATE_H

using namespace std;

class Date {

private:
    int month;
    int day;
    int year;
    char format = 'D';


public:
    Date();
    Date (int month, int day, int year);

    void Input();
    void Show();

    bool Set(int m, int d, int y);

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    bool SetFormat(char f);

    void Increment(int numdays = 1);

    int Compare(const Date& d);








};


#endif //DATE_DATE_H
