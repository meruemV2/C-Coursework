//
// Created by Jerry on 6/26/20.
//


#include <iostream>
#include "square.h"

using namespace std;

Square::Square()
{
    length = MINSIZE;
    area = (length*length);
    perimeter = (4*length);
}
Square::Square(const double a, const double p, const double l)
{
    if (a < MINSIZE)
    {
        area = MINSIZE;
    }
    else
    {
        area = a;
    }
    if (p < MINSIZE)
    {
        perimeter = MINSIZE;
    }
    else
    {
        perimeter = p;
    }
    if (l < MINSIZE)
    {
        length = MINSIZE;
    }
    else
    {
        length = l;
    }
}
void Square::SetLength(const double l)
{
    if (l < MINSIZE)
    {
        length = MINSIZE;
    }
    else
    {
        length = l;
    }
}
double Square::GetLength()
{
    return length;
}
void Square::PrintData()
{
    cout << "Length is: " << length << endl;
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
}