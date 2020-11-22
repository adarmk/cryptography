#include <iostream>
#include <string>
#include "sha256.h"
#include <bitset>

using namespace std;

int main(int argc, char ** argv)
{
    
    Sha256 sha;
    string hashed;
    
    for(int i = 1; i < argc; i++)
    {
        hashed = sha.hash(argv[i]);
        cout << hashed << endl;     
    }
    

    return 0;
}





