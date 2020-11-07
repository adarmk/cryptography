#ifndef INTS_MOD_P
#define INTS_MOD_P


class IntsModP 
{
    int p;

    void extendedEuclideanAlgorithm(int a, int b, int *x, int *y, int *gcd);

    public: 
        IntsModP(int p);
        int mod(int num);
        int add(int num1, int num2);
        int subtract(int num1, int num2);
        int multiply(int num1, int num2);
        int divide(int  num1, int num2);
        int negate(int num1, int num2);
        int mulInv(int num);
        bool isEqual(int num1, int num2);
};


#endif