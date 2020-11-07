// Author: Adar Kahiri
// Reference: http://www.iwar.org.uk/comsec/resources/cipher/sha256-384-512.pdf

#include "sha256.h"

string Sha256::hash(string message) 
{
    string hash; 
    string initialHashes[8] = {"6a09e667", "bb67ae85", "3c6ef372", "a54ff53a", "= 510e527f", "9b05688c", "1f83d9ab", "5be0cd19"};

    long processedMessage = 0;
    int bitLength = message.length() * CHAR_BIT_LEN;
    int padLength;

    //Preprocessing
    
    //1. Converting the string into a unique binary number

    //For each character, bitwise-left-shift the message by the number of bits allocated to a char, and add the next char.
    for(int i = 0; i < message.length(); i++)
    {
        // 'making room' for the next character
        processedMessage <<= CHAR_BIT_LEN;

        //Adding the integer (or binary) value of the character to the message
        processedMessage += (long) message[i];
    }


    //2. Padding the string

    processedMessage <<= 1;
    processedMessage += 1;

    //The goal is to find the smallest positive k such that  bitLength + 1 + k = 448 (mod 512)
    padLength = (448 - (bitLength + 1) % 512 + 512) % 512;

    processedMessage <<= padLength;


    




















    

    return hash;
}