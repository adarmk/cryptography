#include <iostream>
#include <string>
#include "sha256.h"
#include <bitset>

using namespace std;

int main()
{
    
    Sha256 sha;
    
    string hashed = sha.hash("abc");
    cout << hashed << endl << hashed.length();

    return 0;
}





