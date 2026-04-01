#include "crypto.h"
#include <stdexcept>

int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int determinant(const vector<vector<int>>& matrix) {
    return matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])
         - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
         + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
}

vector<vector<int>> adjoint(const vector<vector<int>>& matrix) {
    vector<vector<int>> adj(3, vector<int>(3));

    adj[0][0] =  (matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]);
    adj[0][1] = -(matrix[0][1]*matrix[2][2] - matrix[0][2]*matrix[2][1]);
    adj[0][2] =  (matrix[0][1]*matrix[1][2] - matrix[0][2]*matrix[1][1]);

    adj[1][0] = -(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]);
    adj[1][1] =  (matrix[0][0]*matrix[2][2] - matrix[0][2]*matrix[2][0]);
    adj[1][2] = -(matrix[0][0]*matrix[1][2] - matrix[0][2]*matrix[1][0]);

    adj[2][0] =  (matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
    adj[2][1] = -(matrix[0][0]*matrix[2][1] - matrix[0][1]*matrix[2][0]);
    adj[2][2] =  (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);

    return adj;
}

vector<vector<int>> matrix_mod_inverse(const vector<vector<int>>& matrix, int mod) {
    int det = determinant(matrix);
    int det_mod = (det % mod + mod) % mod;

    int det_inv = mod_inverse(det_mod, mod);
    if (det_inv == -1) throw runtime_error("Not invertible");

    vector<vector<int>> adj = adjoint(matrix);
    vector<vector<int>> inv(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = (adj[i][j] % mod + mod) % mod;
            inv[i][j] = (det_inv * val) % mod;
        }
    }
    return inv;
}

string decrypt_hill(const string& ciphertext, const vector<vector<int>>& key) {
    const int MOD = 26;

    vector<vector<int>> inv = matrix_mod_inverse(key, MOD);

    vector<int> nums;
    for (char c : ciphertext) nums.push_back(c - 'A');

    string plain;

    for (int i = 0; i < nums.size(); i += 3) {
        for (int r = 0; r < 3; r++) {
            int sum = 0;
            for (int c = 0; c < 3; c++) {
                sum += inv[r][c] * nums[i + c];
            }
            plain += char((sum % MOD + MOD) % MOD + 'A');
        }
    }
    return plain;
}