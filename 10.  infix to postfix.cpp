#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of the operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1; // lower precedence
    }
    if (op == '*' || op == '/') {
        return 2; // higher precedence
    }
    return 0;
}

// Function to perform arithmetic operations
int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";

    for (char c : infix) {
        // Skip spaces
        if (c == ' ') continue;

        // If character is an operand (letter or digit)
        if (isalnum(c)) {
            postfix += c;
        }
        // If character is an operator
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        // If character is an opening parenthesis
        else if (c == '(') {
            operators.push(c);
        }
        // If character is a closing parenthesis
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from the stack
        }
    }

    // Pop all the operators remaining in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> values;

    for (char c : postfix) {
        // Skip spaces
        if (c == ' ') continue;

        // If the character is a digit (operand)
        if (isalnum(c)) {
            values.push(c - '0'); // Convert char to integer
        }
        // If the character is an operator
        else if (isOperator(c)) {
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            int result = applyOperator(val1, val2, c);
            values.push(result);
        }
    }

    return values.top(); // The result will be the last value in the stack
}

int main() {
    string infixExpression;
    
    // Input infix expression
    cout << "Enter infix expression (single character operands, operators (+, -, *, /), and no spaces): ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}


// Explanation:
// Infix to Postfix Conversion:

// We iterate through each character in the infix expression.
// Operands (A-Z, a-z, or digits) are directly added to the postfix expression.
// *Operators (+, -, , /) are handled using a stack. If the operator on the stack has higher or equal precedence than the current operator, we pop it to the postfix expression.
// Parentheses are used to group operations. We push a ( to the stack when we encounter it and pop operators to the postfix expression until we encounter a ).
// Postfix Expression Evaluation:

// We evaluate the postfix expression by iterating through it.
// Operands (digits) are pushed to a stack.
// Operators pop two values from the stack, apply the operation, and push the result back onto the stack.
// The final value in the stack will be the result of the evaluation.
// Operator Precedence:

// The precedence of * and / is higher than that of + and -. The algorithm ensures that higher-precedence operators are applied first.

// sample input:A+B*c
