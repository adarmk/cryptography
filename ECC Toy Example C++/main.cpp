#include <iostream>
#include "ellipticcurve.h"
#include "point.h"
#include "idealpoint.h"

int main()
{
    EllipticCurve curve(-1, 1);
    curve.printCurve();

    Point point1(0, 1, curve);
    Point point2(1,0, curve);
    Point point3 = -point1; 
    IdealPoint idealPoint(curve); 

    std::cout << "Point 1: " << point1.getPointStr() << "\t Negative point 1: << " << point3.getPointStr();

    

    return 0;
}
