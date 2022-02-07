//
// Created by Jerry on 6/26/20.
//

#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H

#include <iostream>
#include "shape.h"

using namespace std;

class Circle : public Shape {

public:
    Circle();
    Circle(const double a, const double p, const double r);
    void SetLength(const double r);
    double GetLength();
    virtual void PrintData();
private:
    double length;

};



#endif //SHAPE_CIRCLE_H
