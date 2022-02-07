//
// Created by Jerry on 6/26/20.
//

#ifndef SHAPE_TRIANGLE_H
#define SHAPE_TRIANGLE_H

#include <iostream>
#include "shape.h"

using namespace std;

class Triangle : public Shape{

public:
    Triangle();
    Triangle(const double a, const double p, const double l1, const double l2, const double l3);
    void SetLength1(const double l1);
    void SetLength2(const double l2);
    void SetLength3(const double l3);
    double GetLength1();
    double GetLength2();
    double GetLength3();
    virtual void PrintData();
private:
    double length1;
    double length2;
    double length3;

};



#endif //SHAPE_TRIANGLE_H
