/*
 Calvin Aduma
 */
#ifndef CIPHER_H
#define CIPHER_H
#include "Queue.h"
#include <string>

using namespace std;

class Cipher{
    private:
        Queue cipher_key;
    public:
        // default constructor sets cipher key to 1,2,3,4
        Cipher();

        // sets the cipher key | 1st arg: size of array, 2nd arg: repeating key array
        void setCipher( int, int[] );

        // gets the cipher key
        int* getCipher();

        // encodes string message
        string encodeMessage( string );

        // decodes string message
        string decodeMessage( string );

        // removes whitespace, numbers, and punctuations from string
        string cleanString( string );

        // cipher's message
        void startCipher( string );

        // prints the cipher
        void printCipher( int, int[] );
};

#endif
