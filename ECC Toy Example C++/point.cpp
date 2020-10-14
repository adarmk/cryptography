#include "point.h"

Point::Point(int x, int y, EllipticCurve curve): curve(curve)
{
    this->x = x;
    this->y = y;


    if (!curve.testPoint(this->x, this->y))
    {
        
        string message = "The point (" + to_string(x) + ", " + to_string(y) + ")" + " is not on the given curve."; 

        throw message;
    } 
}

Point::Point(EllipticCurve curve): curve(curve)
{

}

Point Point::operator-()
{
    Point neg_point = Point(x, -y, curve);
    return neg_point;
}

string Point::getPointStr()
{
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}




