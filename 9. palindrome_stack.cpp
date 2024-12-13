#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to print original string followed by reversed string using stack
void printOriginalAndReversed(const string& str) {
    stack<char> s;
    
    // Push each character of the string to the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Print original string
    cout << "Original String: " << str << endl;

    // Print reversed string
    cout << "Reversed String: ";
    while (!s.empty()) {
        cout << s.top();  // Print the top of the stack
        s.pop();  // Pop the top element
    }
    cout << endl;
}

// Function to check whether the given string is a palindrome or not
bool isPalindrome(const string& str) {
    // Remove non-alphanumeric characters and convert to lowercase
    string filteredStr;
    for (char ch : str) {
        if (isalnum(ch)) {
            filteredStr.push_back(tolower(ch));
        }
    }

    // Compare the filtered string with its reverse
    int left = 0, right = filteredStr.size() - 1;
    while (left < right) {
        if (filteredStr[left] != filteredStr[right]) {
            return false;  // Not a palindrome
        }
        left++;
        right--;
    }

    return true;  // Is a palindrome
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Read the full line including spaces

    // Print original and reversed string
    printOriginalAndReversed(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}



















/*

### **Objectives**
1. Understand the **Stack Abstract Data Type (ADT)** and its application.
2. Learn to:
   - Reverse a string using a stack.
   - Check if a string is a palindrome.
   - Handle spaces, punctuation, and case sensitivity in palindrome checks.
3. Explore the practical use of stacks for solving string-based problems.

---

### **Short Theory**

**Stack:**
A stack is a linear data structure that follows the **Last-In-First-Out (LIFO)** principle, where the last element inserted is the first to be removed. It is widely used for temporary storage and reversal operations.

**Key Operations in Stack:**
1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove the element from the top of the stack.
3. **Peek/Top**: Retrieve the element at the top without removing it.
4. **IsEmpty**: Check if the stack is empty.

**Palindrome:**
A palindrome is a sequence of characters that reads the same backward as forward, ignoring spaces, punctuation, and case sensitivity. Examples:
- **Palindrome**: "A man, a plan, a canal: Panama"
- **Not a Palindrome**: "Hello, World!"

**Using Stacks to Check Palindromes:**
1. Push each character of the string onto the stack.
2. Pop characters from the stack to reverse the string.
3. Compare the reversed string with the original string (ignoring spaces and case).

**Steps to Solve the Problem:**
1. **Reverse String**:
   - Traverse the string and push each character onto the stack.
   - Pop characters from the stack and concatenate them to form the reversed string.
2. **Check for Palindrome**:
   - Normalize the string (convert to lowercase and remove non-alphanumeric characters).
   - Compare the normalized string with its reversed version.
3. **Handle Edge Cases**:
   - Empty strings or single-character strings are always palindromes.
   - Strings with special characters or spaces need preprocessing.

**Time Complexity**:
1. **Push/Pop Operations**: O(1) for each character.
2. **String Reversal**: O(n), where (n) is the length of the string.
3. **Palindrome Check**: O(n) for normalization and comparison.

**Space Complexity**:
- O(n), as the stack stores up to (n) characters during reversal.

**Applications**:
- Palindrome checks in natural language processing.
- Reversing sequences (strings, numbers, etc.).
- Parsing expressions in programming languages.

---

This assignment demonstrates the practical application of stacks for string manipulation, helping students understand data structure fundamentals and problem-solving techniques.
*/



