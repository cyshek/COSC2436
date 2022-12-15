#include <iostream>
#include <stack>
using namespace std;

//This is a program that converts an expression represented as a string to a postfix expression and prints it. Program uses stack to store operators and a priority function to determine when to push and pop into the stack.
int priority (char c) {
  if (c == '*' || c == '/') {
    return 2;  
  } else if (c == '+' || c == '-') {
    return 1;
  } else if (c == '(') {
    return 0;
  }
  return -1;
}

int main() {
  string expression = "7*4-(5+7)";
  string postFix = "";
  stack<char> operators;

  for (int i = 0; i < expression.length(); i++) {
    if (isdigit(expression[i])) {
      postFix += expression[i];
    } else if (expression[i] == '(') {
      operators.push(expression[i]);
    } else if (expression[i] == ')') {
      while (!operators.empty() && operators.top() != '(') {
        postFix += operators.top();
        operators.pop();
      }
      operators.pop();
    } else { 
      if (operators.empty()) {
        operators.push(expression[i]);
      } else if (priority(expression[i]) > priority(operators.top())) {
        operators.push(expression[i]);
      } else {
        while (!operators.empty() && priority(expression[i]) <= priority(operators.top())) {
          postFix += operators.top();
          operators.pop();
        }
        operators.push(expression[i]);
      }
    }
  }

  while(!operators.empty()) {
    postFix += operators.top();
    operators.pop();
  }

  cout << "PostFix expression: " << postFix << endl;
}