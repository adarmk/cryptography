#include <iostream>
#include <string>
//#include "point.h"

int main()
{
    int a1 = 1180;
    int b1  = 482;
    int a = a1;
    int b = b1;
    int s;
    int t;
    int gcd;


    //quotient, remainder, coefficient of a, coefficient of b, previous coefficients of a and b
    int q;
    //remainder
    int r;
    //previous coefficients of a and b, respectively
    int s1;
    int s2;
    int t1;
    int t2;

    s1 = 0; 
    s2 = 1; 
    t1 = 1; 
    t2 = 0;

    while(abs(b) > 0)
    {
        //Getting quotient and remainder
        q = a/b;
        r = a % b;

        s = s2 - q * s1;
        t = t2 - q * t1;

        a = b;
        b = r;

        s2 = s1;
        s1 = s;
        t2 = t1;
        t1 = t;
    }

    gcd = a;

    std::cout << a1 << "(" << s2 << ") + " << b1 << "(" << t2 << ") = " << gcd;

    return 0;
}


