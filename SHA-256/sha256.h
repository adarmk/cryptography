// Author: Adar Kahiri
// Reference: http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf

#ifndef SHA256_H
#define SHA256_H

#include <string>

using namespace std;
class Sha256 
{
    const int CHAR_BIT_LEN = 8;

    public: 
        Sha256();
        string hash(string message);
};



#endif