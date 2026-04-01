#include "crypto.h"
#include <cctype>

string preprocess_text(const string& plaintext) {
    string clean;

    for (char ch : plaintext) {
        if (ch != ' ')
            clean += toupper(ch);
    }

    while (clean.length() % 3 != 0)
        clean += 'X';

    return clean;
}