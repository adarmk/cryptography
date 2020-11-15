// Author: Adar Kahiri
// Reference: http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf

#include "sha256.h"

string Sha256::hash(string message) 
{
    string hash = "dd"; 
    string initialHashes[8] = {"6a09e667", "bb67ae85", "3c6ef372", "a54ff53a", "510e527f", "9b05688c", "1f83d9ab", "5be0cd19"};

    int msgBitLen = message.length() * CHAR_BIT_LEN; // Number of chars in message times number of bits in char
    int padLength = (448 - (msgBitLen + 1) % 512 + 512) % 512;  //The goal is to find the smallest positive k such that  bitLength + 1 + k = 448 (mod 512)
    int numBlocks = (msgBitLen + 1 + padLength + 64) / 512; //Each block is 512 bits, so dividing the padded message  by 512 gives the number of blocks

    int **messageBlocks;    //Each block is separated into 32-bit chunks. 512 / 32 = 16.

    messageBlocks = new int*[numBlocks];

    for (int i = 0; i < numBlocks; i++)
    {
        messageBlocks[i] = new int[16];
    }

    //Initializing all array values to zero.
    for (int i = 0; i < numBlocks; i++)
    {
        for (int j = 0; i < 16; i++)
        {
            messageBlocks[i][j] = 0;
        }
    }

    //Preprocessing 

    //Adding message to the array character by character
    for (int i = 0; i < message.length(); i++)
    {
        messageBlocks[i * CHAR_BIT_LEN/512][i * CHAR_BIT_LEN/16] <<= CHAR_BIT_LEN;
        messageBlocks[i * CHAR_BIT_LEN/512][i * CHAR_BIT_LEN/16] += message[i];
    }

    //Getting next block and next section of the block
    int nextBlock = msgBitLen % 512 == 0 ? msgBitLen/512 : (msgBitLen - 1)/512;
    int nextSection = msgBitLen % 32 == 0 ? (msgBitLen/16) % 16 : (msgBitLen - 1)/16;

    //2. Padding the string with a 1. Since all array values have already been set to zero, the remaining 'padding' zeroes are already there. All that is left to add is the message length.
    messageBlocks[nextBlock][nextSection] <<= 1;
    messageBlocks[nextBlock][nextSection] += 1;


    //Appending the message length to the end 
    messageBlocks[numBlocks - 1][15] += msgBitLen;

    return hash;
}


inline int Sha256::ch(int x, int y, int z) 
{
    return (x & y) ^ (~x & z);
}

inline int Sha256::maj(int x, int y, int z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

inline int Sha256::bigSigma0(int x)
{
    return x;
}

inline int Sha256::bigSigma1(int x)
{
    return x;
}

inline int Sha256::sigma0(int x)
{
    return x;
}

inline int Sha256::sigma1(int x)
{
    return x;
}

inline int Sha256::rightRotate(int x, unsigned int n)
{
    //right-shifting n times means the last n bits are deleted, and there are now n zeros where the first n digits used to be. 
    return (x >> n) | (x << (INT_BITS - n));
}

int Sha256::hexToInt(string hex)
{
    int intRep = 0;
    int currentDigit;
    for(int i = hex.length() - 1; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            currentDigit = hex[i] - '0';
        }
        else 
        {
            currentDigit = hex[i] - 87; //Subtracting 87 since 'a' - 87  = 10, 'b' - 87 = 11, ..., 'f' - 87 = 16
        }

        intRep += (int) currentDigit * pow(16, (hex.length() - i - 1));
    }

    return  intRep;
}