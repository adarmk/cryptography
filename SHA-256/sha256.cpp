// Author: Adar Kahiri
// Reference: https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf

#include "sha256.h"

string Sha256::hash(string message) 
{
    stringstream ss;

    static const uint32_t initialHashes[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};

    static const uint32_t K[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t msgBitLen = message.length() * CHAR_BIT_LEN; // Number of chars in message times number of bits in char
    uint32_t padLength = (448 - (msgBitLen + 1) % 512 + 512) % 512;  //The goal is to find the smallest positive k such that  bitLength + 1 + k = 448 (mod 512)
    uint32_t numBlocks = (msgBitLen + 1 + padLength + 64) / 512; //Each block is 512 bits, so dividing the padded message  by 512 gives the number of blocks

    uint32_t **messageBlocks;    //Each block is separated into 32-bit chunks. 512 / 32 = 16.

    messageBlocks = new uint32_t*[numBlocks];

    for (int i = 0; i < numBlocks; i++)
    {
        messageBlocks[i] = new uint32_t[16];
    }


    //Initializing all array values to zero.
    for (int i = 0; i < numBlocks; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            messageBlocks[i][j] = 0;
        }
    }

    // ************** PREPROCESSING ************* 

    //Adding message to the array character by character
    for (int i = 0; i < message.length(); i++)
    {
        messageBlocks[i*CHAR_BIT_LEN/512][(i*CHAR_BIT_LEN/32) % 16] <<= CHAR_BIT_LEN;
        messageBlocks[i*CHAR_BIT_LEN/512][(i*CHAR_BIT_LEN/32) % 16] += message[i];
    }

    //Getting next block and next section of the block
    int nextBlock = msgBitLen % 512 == 0 ? msgBitLen/512 : (msgBitLen - 1)/512;
    int nextSection = msgBitLen % 32 == 0 ? (msgBitLen/32) % 16 : ((msgBitLen - 1)/32) % 16;

    //2. Padding the string with a 1. Since all array values have already been set to zero, the remaining 'padding' zeroes are already there. All that is left to add is the message length.
    messageBlocks[nextBlock][nextSection] <<= 1;
    messageBlocks[nextBlock][nextSection] += 1;

    //Shifting the last few characters of the string so that they end up at the "front" of the word they're in.
    messageBlocks[nextBlock][nextSection] <<= (32 - (msgBitLen % 32) - 1);

    //Appending the message length to the end 
    messageBlocks[numBlocks - 1][15] += msgBitLen;


    // ************** Hash computation ************* 
    uint32_t workingVars[8]; //working variables (a, b, c, ..., f)
    uint32_t hashes[8]; //Array to store the hashes that will be updated in each iteration, and eventually store the final hashes
    uint32_t W[64]; //Message schedule
    uint32_t T_1, T_2; //Temporary words

    //Setting hashes to initial hashes
    for (int i = 0; i < 8; i++)
    {
        hashes[i] = initialHashes[i];
    }

    for (int i = 0; i < numBlocks; i++)
    {
        //Preparing first 16 words in the message schedule
        for(int t = 0; t < 16; t++)
        {
            W[t] = messageBlocks[i][t];
        }

        //Preparing the other 48 words in the message schedule
        for(int t = 16; t < 64; t++)
        {
            W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16];
        }

        //Initializing the 8 working variables
        for(int j = 0; j < 8; j++)
        {
            workingVars[j] = hashes[j];

        }

        for(int t = 0; t < 64; t++)
        {
            
            T_1 = workingVars[7] + bigSigma1(workingVars[4]) + ch(workingVars[4], workingVars[5], workingVars[6]) + K[t] + W[t];
            T_2 = bigSigma0(workingVars[0]) + maj(workingVars[0], workingVars[1], workingVars[2]);

            workingVars[7] = workingVars[6];
            workingVars[6] = workingVars[5];
            workingVars[5] = workingVars[4];
            workingVars[4] = workingVars[3] + T_1;
            workingVars[3] = workingVars[2];
            workingVars[2] = workingVars[1];
            workingVars[1] = workingVars[0];
            workingVars[0] = T_1 + T_2;

            if(t < 30)
            {
                cout << t << ": ";

                for(int p = 0; p < 8; p++)
                {
                    cout << setfill('0') << setw(8) << hex << workingVars[p] << " ";
                }
                cout << endl;
            }
        }

        for(int j = 0; j < sizeof(hashes)/sizeof(hashes[0]); j++)
        {
            hashes[j] = workingVars[j] + hashes[j];
        }
    }

    for(int i = 0; i < sizeof(hashes)/sizeof(hashes[0]); i++)
    {   
        ss << setfill('0') << setw(8) << hex << hashes[i];
    }

    delete[] messageBlocks;
    return ss.str();
}

inline uint32_t Sha256::ch(uint32_t x, uint32_t y, uint32_t z) 
{
    return (x & y) ^ (~x & z);
}

inline uint32_t Sha256::maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t Sha256::bigSigma0(uint32_t x)
{
    return rightRotate(x, 2) ^ rightRotate(x, 13) ^ rightRotate(x, 22);
}

inline uint32_t Sha256::bigSigma1(uint32_t x)
{
    return rightRotate(x, 6) ^ rightRotate(x, 11) ^ rightRotate(x, 25);
}

inline uint32_t Sha256::sigma0(uint32_t x)
{
    return rightRotate(x, 7) ^ rightRotate(x, 18) ^ (x >> 3);
}

inline uint32_t Sha256::sigma1(uint32_t x)
{
    return rightRotate(x, 17) ^ rightRotate(x, 19) ^ (x >> 10);
}

inline uint32_t Sha256::rightRotate(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}