// Author: Adar Kahiri
// Reference: https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf

#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

class Sha256 
{
    static const int CHAR_BIT_LEN = 8;
    static const int INT_BITS = 32;


    public: 
        string hash(string message);
    
    private:
        uint32_t rightRotate(uint32_t x, uint32_t n);
        uint32_t add(uint32_t x, uint32_t y);
        uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
        uint32_t maj(uint32_t x, uint32_t y, uint32_t z);
        uint32_t bigSigma0(uint32_t x);
        uint32_t bigSigma1(uint32_t x);
        uint32_t sigma0(uint32_t x);
        uint32_t sigma1(uint32_t x);
};



#endif