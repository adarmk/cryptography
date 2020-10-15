/*#ifndef IDEALPOINT_H
#define IDEALPOINT_H

class Point; 

class IdealPoint: public Point 
{
    EllipticCurve curve; 

    public:
        IdealPoint(EllipticCurve curve);
        string getPointStr();
        IdealPoint operator-();

 
};

Point operator+(const IdealPoint point1, const Point* point2)
{
    return *point2;
}

Point operator+(const Point* point1, const IdealPoint point2)
{
    return *point1;
}

#endif*/