#include "point.h"

Point::Point(double x, double y, EllipticCurve curve): curve(curve)
{
    isIdeal = false; //If x and y have values, then this point is not ideal

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
    isIdeal = true;
}

EllipticCurve Point::getCurve()
{
    return curve;
}

string Point::getPointStr()
{
    if (isIdeal)
        return "Ideal";
    else
        return "(" + to_string(x) + ", " + to_string(y) + ")";
}


//Group operations
inline Point Point::operator-()
{
    if (!isIdeal)
    {
        return Point(x, -y, curve);
    }
    else
    {
        return *this;
    }  
}



Point Point::operator+(Point& point)
{
    if (isIdeal)
    {
        return point;
    }
    else if (point.isIdeal)
    {
        return *this;
    }
    else
    {
        EllipticCurve curve = this->curve;

        double x_1 = this->x;
        double y_1 = this->y;
        double x_2 = point.x;
        double y_2 = point.y;

        double m; //Will store the value of the tangent or secant  line

        if (x_1 == x_2 && y_1 == y_2) //If point1 and point2 are not distinct
        {
            if (y_1 == 0)
                return Point(curve); //If y is zero, then the implicit derivative at this point is infinite at the limit, meaning the line we get is vertical, which means it passes through the ideal point.

            m = (3*x_1*x_1 + curve.getA()) / (2*y_1); //This is the implicit derivative of the elliptic curve evaluated at (x_1, y_1) or (x_1, y_2) (they're the same point)
        }
        else
        {
            if (x_1 == x_2) //If this is the case, then the line is vertical and so we return the ideal point
                return Point(curve);
            
            m = (y_2 - y_1)/(x_2 - x_1);
        }

        double x_3 = m*m - x_2 - x_1; //Following Vieta's formula, given roots of the polynomial x_i,  x_1 + x_2 + x_3 = -a_2 / a_1. We know that a_1 = 1, a_2 = m^2, and we know the values of x_1 and x_2, so we solve for x_3. 
        double y_3 = m*(x_3 - x_1) + y_1;

        return Point(x_3, -y_3, curve);
    }
}


Point Point::operator-(Point& point)
{
    Point negPoint = -point;
    return *this + negPoint;
}

Point Point::operator*(int n)
{
    Point point = -*this;

    if (n<0)
    {
        
        return point * -n; //Returns the negative of the curve added to itself |n| times
    }
    else if (n == 0)
    {
        return Point(curve); //returns the ideal point
    }
    else //The algorithm here adds points more 
    {
        Point pointToAdd = point; 
        Point sum = (n & 1) == 1 ? point : Point(curve);

        while(n >= 0)
        {
            n = n >> 1;
            pointToAdd = pointToAdd + pointToAdd; 

            if ((n & 1) == 1)
                sum = sum + pointToAdd; 
        }
        return sum;
    }
}