#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    cout << "Enter input (either paste from test.txt or type manually):\n";
    cout << "Format:\n";
    cout << "3x3 key matrix (9 numbers)\n";
    cout << "Plaintext\n\n";

    vector<vector<int>> key(3, vector<int>(3));

    // Read key
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> key[i][j];
        }
    }

    // Read plaintext
    string text;
    cin >> text;

    // Process
    string clean = preprocess_text(text);

    unsigned int hash_before = custom_hash_function(clean);

    string cipher = encrypt_hill(clean, key);
    string decrypted = decrypt_hill(cipher, key);

    unsigned int hash_after = custom_hash_function(decrypted);

    // Output
    cout << "\nPlaintext  : " << clean << endl;
    cout << "Ciphertext : " << cipher << endl;
    cout << "Decrypted  : " << decrypted << endl;

    // Print hash values
    cout << "Hash Before Encryption : " << hash_before << endl;
    cout << "Hash After Decryption  : " << hash_after << endl;

    //Validation message
    if (hash_before == hash_after)
        cout << "Hash Verified: Data Integrity Maintained" << endl;
    else
        cout << "Hash Verification Failed: Data Modified" << endl;

    return 0;
}