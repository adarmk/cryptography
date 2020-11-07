#include <iostream>
#include <string>
#include "point.h"
#include "intsmodp.h"

int main()
{
    IntsModP field(12);

    std::cout << field.mulInv(6);
}


