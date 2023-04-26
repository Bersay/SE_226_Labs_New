#include <iostream>
#include <vector>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    return s == std::string(s.rbegin(), s.rend());
}

std::vector<std::string> palindrome_strings(const std::vector<std::string>& string_list) {
    std::vector<std::string> palindromes;

    for (const std::string& s : string_list) {
        if (is_palindrome(s)) {
            palindromes.push_back(s);
        }
    }

    return palindromes;
}

int main() {
    std::vector<std::string> string_list = {"BERSAY", "YAKICI", "ERDEM", "OKUR", "ADA", "HANNAH"};
    std::vector<std::string> result = palindrome_strings(string_list);

    for (const std::string& s : result) {
        std::cout << s << " ";
    }

    return 0;
}
