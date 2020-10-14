#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <sstream>
#include "ellipticcurve.h"

using namespace std; 


class Point
{
    int x;
    int y;
    EllipticCurve curve;

    public:
        Point(int x, int y, EllipticCurve curve);
        Point(EllipticCurve curve);
        Point operator- ();
        string getPointStr();
};

#endif