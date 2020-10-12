#include "ellipticcurve.h"

EllipticCurve::EllipticCurve(int a, int b)
{
    this->a = a;
    this->b = b;

    discriminant =  -16 * (4 * a*a*a + 27 * b*b);

    std::stringstream ss;

    ss << "y^2 = x^3 + " << a << "x + " << b;
    curveStr = ss.str(); 

    if (!isSmooth())
    {
        ss.str("");
        ss << "The curve " << curveStr << " is not smooth!"; 

        throw ss.str();     
    }
}

bool EllipticCurve::isSmooth()
{
        return discriminant != 0; 
}

bool EllipticCurve::testPoint (int x, int y)
{
    return y*y == x*x*x + a * x + b;
}

void EllipticCurve::printCurve ()
{
    std::cout << curveStr;
}

/*class EllipticCurve
{

    string curveStr;
    int a;
    int b;
    int discriminant;

    public:
        EllipticCurve(int coeff_a, int coeff_b) //Coefficients a and b
        {
            a = coeff_a;
            b = coeff_b;

            discriminant =  -16 * (4 * a*a*a + 27 * b*b);

            std::stringstream ss;
            ss << "y^2 = x^3 + " << a << "x + " << b;
            curveStr = ss.str(); 
    
            if (!isSmooth())
            {
                ss.str("");
                ss << "The curve " << curveStr << " is not smooth!"; 

                throw ss.str();     
            }
        }

    bool isSmooth()
    {
        return discriminant != 0; 
    };

    bool testPoint (int x, int y)
    {
        return y*y == x*x*x + a * x + b;
    };
    
};*/