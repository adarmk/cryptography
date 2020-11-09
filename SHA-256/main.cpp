#include <iostream>
#include <string>
#include "sha256.h"

using namespace std;

int main()
{
    Sha256 sha;
    //long rotated21 = sha.rightRotate(21, 3);
    string hello = "Hello";
    char const *c = hello.c_str();
    
    cout << hello.c_str();

    return 0;
}

//Convert message to binary
//




