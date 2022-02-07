//
// Created by Jerry on 6/26/20.
//

#include "circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle()
{
    length = MINSIZE;
    area = (M_PI*length*length);
    perimeter = (M_PI*2*length);
}
Circle::Circle(const double a, const double p, const double r)
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
    if (r < 1)
    {
        length = MINSIZE;
    }
    else
    {
        length = r;
    }
}
void Circle::SetLength(const double r)
{
    if (r < MINSIZE)
    {
        length = MINSIZE;
    }
    else
    {
        length = r;
    }
}
double Circle::GetLength()
{
    return length;
}
void Circle::PrintData()
{
    cout << "Radius is: " << length << endl;
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
}
