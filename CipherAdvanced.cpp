/*
 Calvin Aduma
 */

#include "Cipher.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CipherAdvanced : public Cipher{
    public:
        // finds possible words recursively
        vector<string> findWords( string word, vector<string> found_words, Queue cipher_key ){
            // base case
            if( word.length() == 0 ) return found_words;

            // compare decoded word to dictionary 
            // @ /usr/share/dict/words

        }

        // fills the cipher array
        void fillArray( int size, int cipher_array[] ){
            switch( size ){
                case 1:
                    for( int num=1; num<10; num++ ){
                        cipher_array[0] = num;
                    }
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
            }
        }

        // deciphers encoding with unknown cipher
        vector<string> unkownScramble( string word, CipherAdvanced cipher_object ){
            vector<string> found_words;
            int cipher_array[5];
            // repeating key is between [n] and [n1,n2,n3,n4,n5]
            // for loop for each index in repeating key
            for( int array_size=0; array_size<5; array_size++ ){
                // loop for current index
                for( int idx=0; idx<=array_size; idx++ ){
                    
                }
                // fill in array
                for( int j=1; j<10; j++ ){
                    cipher_array[i] = j;
                    setCipher( i, cipher_array );
                }
            }

            if( found_words.empty() ) 
                found_words.push_back( "NO POSSIBILITIES EXIST" );
            return found_words; 
        }
};

int main(){
    CipherAdvanced ExtraCredit;
    string word = "random word";
    word = ExtraCredit.cleanString( word );
    ExtraCredit.unkownScramble( word, ExtraCredit );
    return 0;
}
