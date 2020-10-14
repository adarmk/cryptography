#include "point.h"
#include <string>
#include <stdexcept>

using namespace std;

Point::Point(double x, double y, EllipticCurve curve): curve(curve)
{
    this->x = x;
    this->y = y;


    if (!curve.testPoint(this->x, this->y))
    {
        
        string message = "The point (" + to_string(x) + ", " + to_string(y) + ")" + " is not on the given curve."; 

        throw std::invalid_argument( message);
    } 
}

Point::Point(EllipticCurve curve): curve(curve)
{

}


string Point::getPointStr()
{
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}


double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

EllipticCurve Point::getCurve()
{
    return curve;
}

//Group operations
Point Point::operator-()
{
    Point neg_point = Point(x, -y, curve);
    return neg_point;
}




