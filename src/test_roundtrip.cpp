#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    vector<vector<int>> key = {
        {6,24,1},
        {13,16,10},
        {20,17,15}
    };

    // Example 1
    string text = "ACT";
    string cipher = encrypt_hill(text, key);
    unsigned int hash = custom_hash_function(cipher);
    string decrypted = decrypt_hill(cipher, key);

    cout << "Example 1" << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Ciphertext: " << cipher << endl;
    cout << "Hash: " << hex << hash << endl;
    cout << "Decrypted: " << decrypted << endl << endl;

    // Example 2 
    string text2 = "CRYPTOGRAPHY";
    string cipher2 = encrypt_hill(text2, key);
    unsigned int hash2 = custom_hash_function(cipher2);
    string decrypted2 = decrypt_hill(cipher2, key);

    cout << "Example 2" << endl;
    cout << "Plaintext: " << text2 << endl;
    cout << "Ciphertext: " << cipher2 << endl;
    cout << "Hash: " << hex << hash2 << endl;
    cout << "Decrypted: " << decrypted2 << endl << endl;

    // User Input
    string user_input;
    cout << "User Input" << endl;
    cout << "Enter plaintext: ";
    cin >> user_input;

    string user_cipher = encrypt_hill(user_input, key);
    unsigned int user_hash = custom_hash_function(user_cipher);
    string user_decrypted = decrypt_hill(user_cipher, key);

    cout << "Ciphertext: " << user_cipher << endl;
    cout << "Hash: " << hex << user_hash << endl;
    cout << "Decrypted: " << user_decrypted << endl;

    return 0;
}