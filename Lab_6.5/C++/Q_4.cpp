#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string remove_spaces_and_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

std::vector<std::string> anagrams(const std::string& word, const std::vector<std::string>& word_list) {
    std::string sorted_word = remove_spaces_and_lower(word);
    std::sort(sorted_word.begin(), sorted_word.end());

    std::vector<std::string> anagram_list;
    for (const std::string& candidate : word_list) {
        std::string sorted_candidate = remove_spaces_and_lower(candidate);
        std::sort(sorted_candidate.begin(), sorted_candidate.end());

        if (sorted_word == sorted_candidate) {
            anagram_list.push_back(candidate);
        }
    }

    return anagram_list;
}

int main() {
    std::string word = "listen";
    std::vector<std::string> word_list = {"enlist", "google", "inlets", "banana"};
    std::vector<std::string> result = anagrams(word, word_list);

    for (const std::string& s : result) {
        std::cout << s << " ";
    }

    return 0;
}
