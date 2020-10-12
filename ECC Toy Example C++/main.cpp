#include <iostream>
#include "ellipticcurve.h"

int main()
{
    EllipticCurve curve(-1, 1);
    curve.printCurve();
    if (curve.testPoint(0, 1))
        std::cout << "point is on curve";
    else
    {
        std::cout << "point not on curve";
    }

    return 0;
}
