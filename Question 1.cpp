#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <iostream>
#include <string>
#include <stack>
#include <regex>

bool isOperator(char c) {  /* Sets the Operators we could use */
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getPrecedence(char op) {   /* This checks for the precedence of the given Statement */
    if (op == '+' || op == '-')  /* Lower Precedence */
        return 1;
    if (op == '*' || op == '/' || op == '%') /* Higher Precedence */
        return 2;
    return 0;
}

std::string infixToPostfix(std::string infix) {  /* Method to Create Postfix Statement */
    std::string postfix = "";
    std::stack<char> s;

    for (char c : infix) {  
        if (isalnum(c)) {  /* Checks for Alphanumeric Symbols */
            postfix += c;
        }
        else if (c == '(') { /* Pushes ( on the Stack */
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {  /* If ) is found so long as stack is not empty and ( is not found on top */
                postfix += s.top();  /* Postfix will take top element from Stack and then pop the stack */
                s.pop();
            }
            if (!s.empty() && s.top() == '(') { /* If conditions ment then pop the Stack */
                s.pop();
            }
            else {   /* Worst Case: Parathesis do not maych and the Statement is invalid */
                return "Expression is invalid.";
            }
        }
        else if (isOperator(c)) {  /* When an Operator is reached check Precedence and either push onto Stack or pop off*/
            while (!s.empty() && s.top() != '(' && getPrecedence(c) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {  /* While not empty check for either parentheses */
        if (s.top() == '(' || s.top() == ')') {
            return "Expression is invalid."; /* If statement is true, expression is invalid */
        }
        postfix += s.top(); /* Otherwise postfix aquires the top element of stack and then pops */
        s.pop();
    }

    return postfix;
}

bool isBalanced(std::string expr) { /* Use Stack and Regex to Check Validity of Infix Statement */
    std::stack<char> s;
    std::regex pattern("[{}()\\[\\]]");
    for (char c : expr) { /* Will Run Through given Expression to Check that signs are balanced */
        if (std::regex_match(std::string(1, c), pattern)) {
            if (c == '{' || c == '[' || c == '(') {
                s.push(c);
            }
            else {
                if (s.empty()) {
                    return false;
                }
                char top = s.top();
                s.pop();
                if ((c == '}' && top != '{') || (c == ']' && top != '[') || (c == ')' && top != '(')) {
                    return false;
                }
            }
        }
    }
    return s.empty();
}

int main() {   /* Asks User fro an Infix Statement */
    std::string infix;
    std::cout << "Enter an infix expression: ";
    getline(std::cin, infix);

    if (!isBalanced(infix)) {  /* Makes Sure given Expression is Balanced */
        std::cout << "Expression is invalid." << std::endl;
        return 0;
    }

    std::string postfix = infixToPostfix(infix);  /* If Balanced Convert to Postfix and Return it */
    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
#endif // 