//
// Created by Jerry on 6/26/20.
//

#include "rectangle.h"
#include <iostream>

using namespace std;

    Rectangle::Rectangle()
    {
        length1 = MINSIZE;
        length2 = MINSIZE;
        area = (length1*length2);
        perimeter = ((length1*2) + (length2*2));
    }
    Rectangle::Rectangle(const double a, const double p, const double l1, const double l2)
    {
        if (a < 1)
        {
         area = MINSIZE;
        }
        else
        {
            area = a;
        }
        if (p < 1)
        {
           perimeter = MINSIZE;
        }
        else
        {
            perimeter = p;
        }
        if (l1 < 1)
        {
            length1 = MINSIZE;
        }
        else
        {
            length1 = l1;
        }
        if (l2 < 1)
        {
            length2 = MINSIZE;
        }
        else
        {
            length2 = l2;
        }
    }
    void Rectangle::SetLength1(const double l1)
    {
        if (l1 < MINSIZE)
        {
            length1 = MINSIZE;
        }
        else
        {
            length1 = l1;
        }
    }
    void Rectangle::SetLength2(const double l2)
    {
        if (l2 < MINSIZE)
        {
            length2 = MINSIZE;
        }
        else
        {
            length2 = l2;
        }
    }
    double Rectangle::GetLength1()
    {
        return length1;
    }
    double Rectangle::GetLength2()
    {
        return length2; 
    }

void Rectangle::PrintData()
{
        cout << "length 1: " << length1 << endl;
        cout << "length 2: " << length2 << endl;
        cout << "area: " << area << endl;
        cout << "perimeter: " << perimeter << endl;

}
