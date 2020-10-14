#include <iostream>
#include "ellipticcurve.h"
#include "point.h"
#include "idealpoint.h"

int main()
{
    EllipticCurve curve(-1, 1);
    

    Point point1(0, 1, curve);
    Point point3 = -point1; 
    IdealPoint idealPoint(curve); 

    curve.printCurve();

    std::cout << "Point 1: " << point1.getPointStr() << "\t Negative point 1: << " << point3.getPointStr() << "\n";

    
    

    return 0;
}
