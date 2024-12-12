# Function to display the word with the longest length
def longest_word(string):
    words = []
    word = ""
    for char in string:
        if char == ' ':
            if word:
                words.append(word)
            word = ""
        else:
            word += char
    if word:
        words.append(word)

    max_length = 0
    longest = ""
    for w in words:
        length = 0
        for _ in w:
            length += 1
        if length > max_length:
            max_length = length
            longest = w
    return longest

# Function to determine the frequency of occurrence of a particular character
def char_frequency(string, char):
    count = 0
    for c in string:
        if c == char:
            count += 1
    return count

# Function to check whether the given string is a palindrome
def is_palindrome(string):
    cleaned = ""
    for c in string:
        if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'):
            if c >= 'A' and c <= 'Z':
                cleaned += chr(ord(c) + 32)
            else:
                cleaned += c

    length = 0
    for _ in cleaned:
        length += 1

    for i in range(length // 2):
        if cleaned[i] != cleaned[length - i - 1]:
            return False
    return True

# Function to display the index of the first appearance of a substring
def first_substring_index(string, substring):
    n = 0
    for _ in string:
        n += 1
    m = 0
    for _ in substring:
        m += 1

    for i in range(n - m + 1):
        match = True
        for j in range(m):
            if string[i + j] != substring[j]:
                match = False
                break
        if match:
            return i
    return -1

# Function to count the occurrences of each word in a string
def word_count(string):
    words = []
    word = ""
    for char in string:
        if char == ' ':
            if word:
                found = False
                for i in range(len(words)):
                    if words[i][0] == word:
                        words[i][1] += 1
                        found = True
                        break
                if not found:
                    words.append([word, 1])
                word = ""
        else:
            word += char
    if word:
        found = False
        for i in range(len(words)):
            if words[i][0] == word:
                words[i][1] += 1
                found = True
                break
        if not found:
            words.append([word, 1])

    return words

# Input a string from the user
input_string = input("Enter a string: ")

# a) Display the word with the longest length
print("\nWord with the longest length:", longest_word(input_string))

# b) Determine the frequency of occurrence of a particular character
char = input("\nEnter a character to find its frequency: ")
print(f"Frequency of '{char}':", char_frequency(input_string, char))

# c) Check whether the given string is a palindrome or not
print("\nIs the string a palindrome?:", is_palindrome(input_string))

# d) Display the index of the first appearance of a substring
substring = input("\nEnter a substring to find its first occurrence: ")
index = first_substring_index(input_string, substring)
if index != -1:
    print(f"First appearance of '{substring}' is at index: {index}")
else:
    print(f"'{substring}' not found in the string.")

# e) Count the occurrences of each word in the given string
word_occurrences = word_count(input_string)
print("\nOccurrences of each word:")
for word, count in word_occurrences:
    print(f"{word}: {count}")
