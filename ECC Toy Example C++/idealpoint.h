#ifndef IDEALPOINT_H
#define IDEALPOINT_H

#include "point.h"

class IdealPoint: public Point 
{
    EllipticCurve curve; 
    
    public:
        IdealPoint(EllipticCurve curve);
        string printPoint();
        void operator-();

 
};

#endif