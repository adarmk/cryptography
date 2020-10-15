#ifndef ELLIPTICCURVE_H
#define ELLIPTICCURVE_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class EllipticCurve
{
    string curveStr;
    double a;
    double b;
    double discriminant;

    public:
        EllipticCurve(double a, double b);
        bool testPoint(double x, double y); 
        void printCurve();
        string getCurveStr();
        double getA();


    bool isSmooth(); 
};

#endif