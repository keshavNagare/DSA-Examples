#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Node {
public:
char data;
Node* next;
Node(char value) : data(value), next(nullptr) {}
};

class Stack {
private:
Node* top;
public:
Stack() : top(nullptr) {}
bool isEmpty() {
return top == nullptr;
}
void push(char value) {
Node* newNode = new Node(value);
newNode->next = top;
top = newNode;
}
char pop() {
if (isEmpty()) {
cerr << "Stack is empty." << endl;
return '\0';
}
char value = top->data;
Node* temp = top;
top = top->next;
delete temp;
return value;
}
char peek() {
if (isEmpty()) {
cerr << "Stack is empty." << endl;
return '\0';
}
return top->data;
}
};
bool isOperand(char c) {
return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int getPrecedence(char op) {
switch (op) {
case '^':
return 3;
case '*':
case '/':
return 2;
case '+':
case '-':
return 1;
default:
return -1;
}
}
string infixToPostfix(const string& infix) {
string postfix;
Stack stack;
for (char c : infix) {
if (isOperand(c)) {
postfix += c;
} else if (c == '(') {
stack.push(c);
} else if (c == ')') {
while (!stack.isEmpty() && stack.peek() != '(') {
postfix += stack.pop();
}
stack.pop(); 
} else { 
while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.peek())) {
postfix += stack.pop();
}
stack.push(c);
}
}
while (!stack.isEmpty()) {
postfix += stack.pop();
}
return postfix;
}
int main() {
string infixExpression;
cout << "\nEnter an infix expression: ";
getline(cin, infixExpression);
string postfixExpression = infixToPostfix(infixExpression);
cout << "\nPostfix expression: " << postfixExpression << endl;
cout<<"\n";
return 0;
}