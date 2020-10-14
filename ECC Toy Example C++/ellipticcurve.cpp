#include "ellipticcurve.h"

EllipticCurve::EllipticCurve(double a, double b)
{
    this->a = a;
    this->b = b;

    discriminant =  -16 * (4 * a*a*a + 27 * b*b);

    std::stringstream ss;

    ss << "y^2 = x^3 + " << a << "x + " << b << "\n";
    curveStr = ss.str(); 

    if (!isSmooth())
    {
        string message = "The curve " + curveStr + " is not smooth!"; 

        throw message;     
    }
}

bool EllipticCurve::isSmooth()
{
        return discriminant != 0; 
}

bool EllipticCurve::testPoint (double x, double y)
{
    return y*y == x*x*x + a * x + b;
}

void EllipticCurve::printCurve ()
{
    std::cout << curveStr;
}

string EllipticCurve::getCurveStr ()
{
    return curveStr;
}

double EllipticCurve::getA()
{
    return a;
}