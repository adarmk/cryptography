#include <iostream>
#include <string>
#include "sha256.h"

using namespace std;

int main()
{
    Sha256 sha;

    cout << sha.hexToInt("100") << endl;
    cout << sha.hexToInt("a") << endl;
    cout << sha.hexToInt("f") << endl;
    cout << sha.hexToInt("6a09e667") << endl;

    return 0;
}

//Convert message to binary
//




