#include <iostream>
#include <stack>
using namespace std;


//This is a program that converts an expression to a postfix expression and solves it, returning and printing the result. The program relys on stack operations, priority function, and a postfix expression.
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

float solvePostFix (string postExp) {
  float result;
  float lhs, rhs;
  stack<string> stack;
  for (int i = 0; i < postExp.length(); i++) {
    if (isdigit(postExp[i])) {
      stack.push(postExp.substr(i, 1));
    } else if (postExp[i] == '-') {
      lhs = stof(stack.top());
      stack.pop();
      rhs = stof(stack.top());
      stack.pop();
      result = rhs - lhs;
      stack.push(to_string(result));           
    } else if (postExp[i] == '+') {
      lhs = stof(stack.top());
      stack.pop();
      rhs = stof(stack.top());
      stack.pop();
      result = rhs + lhs;
      stack.push(to_string(result));              
    } else if (postExp[i] == '*') {
      lhs = stof(stack.top());
      stack.pop();
      rhs = stof(stack.top());
      stack.pop();
      result = rhs * lhs;
      stack.push(to_string(result));        
    } else if (postExp[i] == '/') {
      lhs = stof(stack.top());
      stack.pop();
      rhs = stof(stack.top());
      stack.pop();
      result = rhs / lhs;
      stack.push(to_string(result));
    }
  }
  return result;
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
  cout << "Solved: " << solvePostFix(postFix) << endl;
}