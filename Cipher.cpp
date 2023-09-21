/* Calvin Aduma
 */

#include "Cipher.h"
#include "Queue.h"
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

Cipher::Cipher(){
    for( int i=0; i<4; i++ ) cipher_key.enqueue( i+1 );
}

void Cipher::setCipher( int n, int key[] ){
    Queue temp_key;
    for( int i=0; i<n; i++ ) temp_key.enqueue( key[i] );
    cipher_key = temp_key;
}

int* Cipher::getCipher(){
    Queue::linked_list *temp = cipher_key.front();
    
    int size = cipher_key.getSize();

    int* cipher_key_array = new int[ size ];
    for( int i=0; i<size; i++ ){
        cipher_key_array[i] = temp->data;
        temp =  temp->next;
    }
    return cipher_key_array;
}

string Cipher::encodeMessage( string in ){
    char letter;
    int key;
    Queue::linked_list* current = cipher_key.front();
    for( size_t i=0; i<in.size(); i++ ){
        letter = in[i];
        key = current->data;
        /* if letter + cipher is greater than max ascii lower case decimal value
         * then MOD by max ascii lower case decimal value
         * and add lowest ascii lower case decimal value - 1
         * ELSE, add letter + cipher normally
         */
        in[i] = ( letter+key <= 'z' ) ? letter+key : ((letter+key)%'z')+96;
        
        // reset cipher key to front if reached end of cipher
        if( current->next == NULL ) current = cipher_key.front();
        else current = current->next;
    }
    return in;
}

string Cipher::decodeMessage( string in ){
    char letter;
    int key;
    Queue::linked_list* current = cipher_key.front();
    for( size_t i=0; i<in.size(); i++ ){
        letter = in[i];
        key = current->data;
        /* if letter - cipher is less than lowest ascii lower case decimal value
         * then subtract the MOD of lowest ascii lower case decimal value
         * and (letter - cipher) 
         * from max ascii lower case decimal value
         * ELSE, add letter - cipher normally
         */
        in[i] = ( letter-key >= 'a' ) ? letter-key : 'z'-(96%(letter-key));

        // reset cipher key to front if reached end of cipher
        if( current->next == NULL ) current = cipher_key.front();
        else current = current->next;
    }
    return in;
}

string Cipher::cleanString( string in ){
    for( size_t i=0; i<in.size(); i++ ){
        if( !isalpha( in[i] ) ){
            in.erase( i, 1 );
            i--; // subtract 1 to account for loss in size of string
        } else { // make sure everything is lower case
            in[i] = tolower( in[i] );
        }
    }
    return in;
}

void Cipher::startCipher( string in ){
    int* cipher_array = getCipher();
    int size = cipher_key.getSize();
    printCipher( size, cipher_array );
    cout << "Encoding: " << in << endl;
    in = cleanString( in );
    string in2 = encodeMessage( in );
    cout << "Encoded: " << in2 << endl;

    cout << endl;
    printCipher( size, cipher_array );
    cout << "Decoding: " << in2 << endl;
    string in3 = decodeMessage( in2 );
    cout << "Decoded: " << in3 << endl << endl;
}

void Cipher::printCipher( int size, int cipher_array[] ){
    cout << "Key: [";
    for( int i=0; i<size; i++ ){
        if( i==size-1 ) cout << cipher_array[i];
        else cout << cipher_array[i] << ", ";
    }
    cout << "]" << endl;
}
