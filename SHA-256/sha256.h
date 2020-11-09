// Author: Adar Kahiri
// Reference: http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf

#ifndef SHA256_H
#define SHA256_H

#include <string>

using namespace std;

class Sha256 
{
    const int CHAR_BIT_LEN = 8;
    const int LONG_BITS = 32;


    public: 
        string hash(string message);
        int rightRotate(int x, unsigned int n);

    //Auxiliary functions
    int ch(int x, int y, int z);
    int maj(int x, int y, int z);
    int bigSigma0(int x);
    int bigSigma1(int x);
    int sigma0(int x);
    int sigma1(int x);
};



#endif