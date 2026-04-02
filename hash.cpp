#include "crypto.h"

unsigned int custom_hash_function(const string& text) {
    const unsigned int OFFSET = 0x811C9DC5;
    const unsigned int PRIME = 0x01000193;

    unsigned int hash = OFFSET;

    for (char ch : text) {
        hash ^= (unsigned int)ch;
        hash *= PRIME;
    }

    return hash;
}