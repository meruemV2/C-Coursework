//
// Created by Jerry on 6/26/20.
//

#ifndef SHAPE_RECTANGLE_H
#define SHAPE_RECTANGLE_H

#include <iostream>
#include "shape.h"

using namespace std;

class Rectangle : public Shape{

public:
    Rectangle();
    Rectangle(const double a, const double p, const double l1, const double l2);
    void SetLength1(const double length1);
    void SetLength2(const double length2);
    double GetLength1();
    double GetLength2();
    virtual void PrintData();
private:
    double length1;
    double length2;

};


#endif //SHAPE_RECTANGLE_H
