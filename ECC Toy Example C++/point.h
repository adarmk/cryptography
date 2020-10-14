#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <sstream>
#include "ellipticcurve.h"
#include "idealpoint.h"

using namespace std; 


class Point
{
    double x;
    double y;
    EllipticCurve curve;

    public:
        Point(double x, double y, EllipticCurve curve);
        Point(EllipticCurve curve);
        Point operator- ();
        string getPointStr();
        double getX();
        double getY();
        EllipticCurve getCurve();

        
};

Point operator+(Point& point1, Point& point2)
{
    EllipticCurve curve = point1.getCurve();
    double x_1 = point1.getX();
    double y_1 = point1.getY();
    double x_2 = point2.getX();
    double y_2 = point2.getY();

    double m; //Will store the value of the tangent or secant  line

    if(x_1 == x_2 && y_1 == y_2) //If point1 and point2 are not distinct
    {
        if (y_1 == 0)
            return IdealPoint(curve); //If y is zero, then the implicit derivative at this point is infinite at the limit, meaning the line we get is vertical, which means it passes through the ideal point.

        m = (3*x_1*x_1 + curve.getA()) / (2*y_1); //This is the implicit derivative of the elliptic curve evaluated at (x_1, y_1) or (x_1, y_2) (they're the same)
    }
    else
    {
        if (x_1 == x_2) //If this is the case, then the line is vertical and so we return the ideal point
            return IdealPoint(curve);
    }

    double x_3 = m*m - x_2 - x_1;
    double y_3 = m*(x_3 - x_1) + y_1;

    return Point(x_3, y_3, curve);
}



#endif