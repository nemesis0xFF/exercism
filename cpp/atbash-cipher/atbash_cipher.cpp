#include "atbash_cipher.h"
// #include <cctype>
// #include <string>

namespace atbash_cipher {

// TODO: add your solution here
std::string encode(const std::string& input) {
    std::string raw;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    const std::string reversed_alphabet = "zyxwvutsrqponmlkjihgfedcba";

    for (char c : input) {
        if (isalpha(c)) {
            size_t index = alphabet.find(tolower(c));
            if (index != std::string::npos) {
                raw += reversed_alphabet[index];
            }
        } else if (isdigit(c)) {
            raw += c;
        }
    }

    std::string result;
    for (size_t i = 0; i < raw.size(); ++i) {
        if (i > 0 && i % 5 == 0) {
            result += ' ';
        }
        result += raw[i];
    }

    return result;
}


std::string decode(const std::string& input) {
    std::string result;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    const std::string reversed_alphabet = "zyxwvutsrqponmlkjihgfedcba";
    for (char c : input) {
        if (isalpha(c)) {
            size_t index = reversed_alphabet.find(tolower(c));
            if (index != std::string::npos) {
                result += alphabet[index];
            }
        } else if (isdigit(c)) {
            result += c;
        }
    }
    return result;
}
}  // namespace atbash_cipher
