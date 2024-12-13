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






















'''///OBJECTIVES///

Understand string manipulation using Python’s array-like structure and built-in library functions.
Learn to perform various string operations, including:
Finding the word with the longest length.
Calculating the frequency of a specific character in the string.
Checking if a string is a palindrome.
Identifying the index of the first appearance of a substring.
Counting occurrences of each word in the string.
Practice using character arrays to represent strings and perform operations on them.


///THEORY///
Strings in Python: A string is a sequence of characters. Python strings are immutable, meaning their content cannot be modified directly. However, they support a wide variety of operations, making them highly versatile for text processing.

Key Features of Strings in Python:

Strings can be created using single, double, or triple quotes.
They support indexing and slicing for accessing and manipulating individual or grouped characters.
Strings are iterable, allowing easy traversal using loops.
Common String Operations:

Length Calculation: Measure the length of a string using the len() function.
Character Frequency: Use the count() method to determine how often a character appears.
Palindrome Check: Reverse the string (using slicing or a loop) and compare it with the original.
Substring Index: Use the find() or index() methods to locate the first occurrence of a substring.
Word Count: Split the string into words (using the split() method) and count occurrences using a dictionary or similar structure.
Applications: String operations are crucial in areas like text analysis, data parsing, and natural language processing. By applying these concepts, one can efficiently handle tasks such as searching, filtering, and modifying textual data.

'''
