#include <iostream>
#include <string>
#include "point.h"


int main()
{
    EllipticCurve curve(-1, 1);

    Point ideal(curve);

    Point point1(0, 1, curve);
    std::cout << "Point 1: " << point1.getPointStr() << "\n";
    Point point2(3,5, curve);
    std::cout << "Point 2: " <<point2.getPointStr() << "\n";
    Point neg_point1 = -point1;
    std::cout << "Negative Point 1: " << neg_point1.getPointStr() << "\n";
    //Point point3 = point1 + point2;
    //std::cout << "Point 3: " <<point3.getPointStr() << "\n";
    Point point4 = point1 + neg_point1;
    std::cout << "Point 4: " << point4.getPointStr() << "\n";

    Point point5 = point1 + ideal;
    std::cout << "Point 5: " << point5.getPointStr() << "\n";
    curve.printCurve();

    Point point6 = 2*point1;
    std::cout << "Point 6: " << point6.getPointStr() << "\n";

    return 0;
}
