#include <iostream>
#include <string>
#include "sha256.h"

using namespace std;

int main()
{
    Sha256 sha;
    cout << sha.hash("Hello!");
    return 0;
}

//Convert message to binary
//




