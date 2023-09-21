

#include "Cipher.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Cipher Encryption;
    string name = "Secret Message!";
    Encryption.startCipher( name );
    return 0;
}