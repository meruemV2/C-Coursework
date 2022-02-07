//
// Created by Jerry on 6/26/20.
//

#include "triangle.h"
#include <cmath>
#include <iostream>

using namespace std;
//Assume we know three sides (Side1, Side2, Side3)
// then the area based on Heron’s formula which gives the area
// in terms of the three sides of the triangle.
// First calculate s which is (Side1 + Side2 + Side3)/2.
// Then obtain the square root of the absolute value of
// following formula: s*(s – Side1)*(s – Side2)*(s – Side3).
Triangle::Triangle()
{
    length1 = MINSIZE;
    length2 = MINSIZE;
    length3 = MINSIZE;
    double s = ((length1 + length2 + length3)/2);
    double ss = (s*(s-length1)*(s-length2)*(s-length3));
    ss = sqrt(abs(ss));
    area = ss;
    perimeter = (length1 + length2 + length3);
}
Triangle::Triangle(const double a, const double p, const double l1, const double l2, const double l3)
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
    if (l3 < 1)
    {
        length3 = MINSIZE;
    }
    else
    {
        length3 = l3;
    }
}
void Triangle::SetLength1(const double l1)
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
void Triangle::SetLength2(const double l2)
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
void Triangle::SetLength3(const double l3)
{
    if (l3 < MINSIZE)
    {
        length3 = MINSIZE;
    }
    else
    {
        length3 = l3;
    }
}
double Triangle::GetLength1()
{
    return length1;
}
double Triangle::GetLength2()
{
    return length2;
}
double Triangle::GetLength3()
{
    return length3;
}
void Triangle::PrintData()
{
    cout << "Length 1: " << length1 << endl;
    cout << "Length 2: " << length2 << endl;
    cout << "Length 3: " << length3 << endl;
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
}
