#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <vector>

using namespace std;

// Encryption
string encrypt_hill(const string& plaintext, const vector<vector<int>>& key);

// Decryption
string decrypt_hill(const string& ciphertext, const vector<vector<int>>& key);

// Hash
unsigned int custom_hash_function(const string& text);

// Utils
string preprocess_text(const string& plaintext);

#endif