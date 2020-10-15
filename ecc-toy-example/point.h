#ifndef POINT_H
#define POINT_H

#include "ellipticcurve.h"
#include <stdexcept>

using namespace std; 

class Point
{
    bool isIdeal;
    double x;
    double y;
    EllipticCurve curve;

    public:
        Point(double x, double y, EllipticCurve curve); 
        Point(EllipticCurve curve); //Point constructed without x and y initialized is considered an 'ideal point' 
        Point operator- ();
        Point operator+(Point& point);
        Point operator-(Point& point);
        Point operator*(int n);
        string getPointStr();
        double getX();
        double getY();
        EllipticCurve getCurve();

        
};

inline Point operator*(int n, Point& point)
{
    return point * n;
}



#endif