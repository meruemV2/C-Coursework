//
// Created by Jerry on 6/26/20.
//

#include "shape.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
    area = MINSIZE;
    perimeter = MINSIZE;
}

Shape::Shape(const double a, const double p)
{
    if (a < 1)
    {
        area = MINSIZE;
    }
    else
    {
        area = a;
    }

    if( p < 1)
    {
        perimeter = MINSIZE;
    }
    else
    {
        perimeter = p;
    }
}

double Shape::GetArea()
{
    return area;
}

double Shape::GetPerimeter()
{
    return perimeter;
}
void Shape::SetArea (const double inputarea)
{
    double temparea = inputarea;

    if (temparea < 1)
    {
        area = MINSIZE;
    }
    else
    {
        area = temparea;
    }
}
void Shape::SetPerimeter (const double inputperimeter)
{
    if (inputperimeter < MINSIZE)
    {
        perimeter = MINSIZE;
    }
    else
    {
        perimeter = inputperimeter;
    }
}
void Shape::PrintData()
{
    cout << "No Specific shape detected..." << endl;
}