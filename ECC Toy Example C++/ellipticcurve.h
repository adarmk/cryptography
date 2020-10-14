#ifndef ELLIPTICCURVE_H
#define ELLIPTICCURVE_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class EllipticCurve
{
    string curveStr;
    int a;
    int b;
    int discriminant;

    public:
        EllipticCurve(int a, int b);
        bool testPoint(int x, int y); 
        void printCurve();
        string getCurveStr();

    bool isSmooth(); 
};

#endif