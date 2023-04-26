def is_palindrome(s):
    return s == s[::-1]

def palindrome_strings(string_list):
    palindromes = [s for s in string_list if is_palindrome(s)]

    return palindromes

string_list = ["BERSAY", "YAKICI", "ERDEM", "OKUR", "ADA", "HANNAH"]

result = palindrome_strings(string_list)
print(result)