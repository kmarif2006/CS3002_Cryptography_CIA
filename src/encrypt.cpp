#include "crypto.h"

string encrypt_hill(const string& plaintext, const vector<vector<int>>& key) {
    const int MOD = 26;
    string clean = preprocess_text(plaintext);

    vector<int> nums;
    for (char c : clean) nums.push_back(c - 'A');

    string cipher;

    for (int i = 0; i < nums.size(); i += 3) {
        for (int r = 0; r < 3; r++) {
            int sum = 0;
            for (int c = 0; c < 3; c++) {
                sum += key[r][c] * nums[i + c];
            }
            cipher += char((sum % MOD) + 'A');
        }
    }
    return cipher;
}