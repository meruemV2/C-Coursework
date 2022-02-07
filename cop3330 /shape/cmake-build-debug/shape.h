//
// Created by Jerry on 6/26/20.
//

#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H

#include <iostream>
using namespace std;

const double MINSIZE = 1;

class Shape {

protected: //can be accessed by children of class
    double area;
    double perimeter;

private:

public:
    Shape();
    Shape (const double a, const double p);
    double GetArea();
    double GetPerimeter();
    void SetArea (const double inputarea);
    void SetPerimeter (const double inputperimeter);
    virtual void PrintData()=0; //pure virtual function

};


#endif //SHAPE_SHAPE_H
