#include "idealpoint.h"


IdealPoint::IdealPoint (EllipticCurve curve): Point(curve), curve(curve)
{
}

string IdealPoint::printPoint ()
{
    return "Ideal";
}

void IdealPoint::operator-()
{

}