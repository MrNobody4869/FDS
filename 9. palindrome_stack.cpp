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
