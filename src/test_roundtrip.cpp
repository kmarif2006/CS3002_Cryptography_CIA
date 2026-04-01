#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    vector<vector<int>> key = {
        {6,24,1},
        {13,16,10},
        {20,17,15}
    };

    string text = "ACT";

    string cipher = encrypt_hill(text, key);
    unsigned int hash = custom_hash_function(cipher);
    string decrypted = decrypt_hill(cipher, key);

    cout << "Plaintext: " << text << endl;
    cout << "Ciphertext: " << cipher << endl;
    cout << "Hash: " << hex << hash << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}