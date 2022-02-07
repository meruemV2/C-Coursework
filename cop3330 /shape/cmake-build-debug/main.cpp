//
// Created by Jerry on 6/26/20.
//

#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
using namespace std;

int main(void)
{
    Rectangle Rectangle1(9,11,2,4);
    Rectangle1.PrintData();
    Rectangle Rectangle2;
    Rectangle2.SetLength2(2);
    Rectangle2.SetLength1(3);
    cout << Rectangle2.GetLength1() << endl;
    cout  << Rectangle1.GetArea() << endl;
    Square Square1(4,4,1);
    Square1.PrintData();
    Square Square2(16,16,4);
    Square2.SetLength(2);
    Square2.SetArea(4);
    Square2.SetPerimeter(8);
    Square2.PrintData();
    cout << Square1.GetPerimeter() << endl;
    Circle Circle1;
    Circle1.PrintData();
    Circle Circle2(5,7,2);
    Circle2.SetLength(10);
    Circle2.SetPerimeter(50);
    cout << Circle1.GetArea() << endl;
    Triangle Triangle1;
    Triangle1.PrintData();
    Triangle Triangle2(12,9,1,2,3);
    Triangle2.SetLength1(3);
    Triangle2.SetLength2(3);
    Triangle2.SetLength3(3);
    cout  << Triangle2.GetPerimeter() << endl;
    return 0;
}