#include "intsmodp.h"


IntsModP::IntsModP(int p) {
    this->p = p;
}

//This replaces the standard modulo operator '%' in C++. It does the same thing for positive values, but returns the expected value of the 'mathematical' modulo operator for negative numbers.
int IntsModP::mod(int num)
{
    return (num%p + p) % p;
}

int IntsModP::add(int num1, int num2)
{
    return mod(num1 + num2);
}

int IntsModP::subtract(int num1, int num2)
{
    return mod(num1 - num2);
}

int IntsModP::multiply(int num1, int num2)
{
    return mod(num1 * num2);
}

int IntsModP::divide(int num1, int num2)
{
    return mod(num1 * mulInv(num2));
}

//This needs to be fixed
int IntsModP::mulInv(int num)
{
    int s;
    int t;
    int gcd;

    extendedEuclideanAlgorithm(num, p, &s, &t, &gcd);

    return mod(t);
}

bool IntsModP::isEqual(int num1, int num2)
{
    return mod(num1) == mod(num2);
}

void IntsModP::extendedEuclideanAlgorithm(int a, int b, int *s, int *t, int *gcd)
{

    //a must be larger than b for this algorithm to work, so if that's not the case we just switch them
    if (abs(b) > abs(a))
    {
        extendedEuclideanAlgorithm(b, a, x, y, gcd);
    }
    else 
    {
        if (abs(b) == 0)
        {
            *s = 1;
            *t = 0;
            *gcd = a;
        }
        else 
        {
            
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

                *s = s2 - q * s1;
                *t = t2 - q * t1;

                a = b;
                b = r;
                s2 = s1;
                s1 = *s;
                t2 = t1;
                t1 = *t;
            }

            *s = s2;
            *t = t2;
            *gcd = a;
        }
    }
}