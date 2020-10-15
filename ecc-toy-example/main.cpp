#include <iostream>
#include <string>
#include "point.h"


int main()
{
    EllipticCurve curve(-1, 1);

    Point ideal(curve);

    Point point1(0, 1, curve);
    std::cout << "Point 1: " << point1.getPointStr() << "\n";
    Point point2 = point1 + point1 + point1 + point1;
    std::cout << "Point 2: " << point2.getPointStr() << "\n";
    Point point3 = 4*point1; 
    std::cout << "Point 3: " << point3.getPointStr() << "\n";

    return 0;
}
