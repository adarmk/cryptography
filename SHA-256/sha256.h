// Author: Adar Kahiri
// Reference: https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf

#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Sha256 
{
    static const int CHAR_BIT_LEN = 8;
    static const int INT_BITS = 32;


    public: 
        string hash(string message);
        int rightRotate(int x, unsigned int n);

    //Auxiliary functions
    private: 
        int add(int x, int y);
        int ch(int x, int y, int z);
        int maj(int x, int y, int z);
        int bigSigma0(int x);
        int bigSigma1(int x);
        int sigma0(int x);
        int sigma1(int x);
        int hexToInt(string hex);
};



#endif