def anagrams(word, word_list):
    word = sorted(word.lower().replace(" ", ""))

    anagram_list = []

    for candidate in word_list:
        candidate_sorted = sorted(candidate.lower().replace(" ", ""))

        if word == candidate_sorted:
            anagram_list.append(candidate)

    return anagram_list

word = "listen"
word_list = ["enlist", "google", "inlets", "banana"]

result = anagrams(word, word_list)
print(result)