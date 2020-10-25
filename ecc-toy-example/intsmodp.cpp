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
    return mod(1/num);
}

bool IntsModP::isEqual(int num1, int num2)
{
    return mod(num1) == mod(num2);
}