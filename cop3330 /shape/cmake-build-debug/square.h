//
// Created by Jerry on 6/26/20.
//

#ifndef SHAPE_SQUARE_H
#define SHAPE_SQUARE_H
#include <iostream>
#include "shape.h"

using namespace std;

class Square : public Shape{

public:
    Square();
    Square(const double a, const double p, const double l);
    void SetLength(const double length);
    double GetLength();
    void PrintData();

private:
    double length;

};


#endif //SHAPE_SQUARE_H
