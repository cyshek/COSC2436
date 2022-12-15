#include <iostream>
#include <stack>
#include <fstream>
#include <iomanip>
#include "ArgumentManager.h"

using namespace std;

int precedence (string str) {
  if (str == "*" || str == "/") {
    return 2;
  } else if (str == "+" || str == "-") {
    return 1;
  } else if (str == "(") {
    return 0;
  }
  return -1;
}

void solveExpression(stack<string>& expression, string postfix_expression, float result, ostream& output) {
  string temp;    //Store the character in a string since stack is of type string
  string lhs, rhs;
  float current;
  for (int i = 0; i < postfix_expression.length(); i++) {
    if (isdigit(postfix_expression[i]) || postfix_expression[i] == 'x') {
      temp = postfix_expression[i];
      expression.push(temp);
    } else if (postfix_expression[i] == '+') {
      lhs = expression.top();
      expression.pop();
      rhs = expression.top();
      expression.pop();
      if (lhs == "x" || rhs == "x") {
        lhs == "x" ? result -= stof(rhs) : result -= stof(lhs);
      } else {
        current = stof(rhs) + stof(lhs);
        expression.push(to_string(current));
      }
    } else if (postfix_expression[i] == '-') {
      lhs = expression.top();
      expression.pop();
      rhs = expression.top();
      expression.pop();
      if (lhs == "x" || rhs == "x") {
        lhs == "x" ? result += stof(rhs) : result += stof(lhs);
      } else {
        current = stof(rhs) - stof(lhs);
        expression.push(to_string(current));
      }     
    } else if (postfix_expression[i] == '*') {
      lhs = expression.top();
      expression.pop();
      rhs = expression.top();
      expression.pop();
      if (lhs == "x" || rhs == "x") {
        lhs == "x" ? result /= stof(rhs) : result /= stof(lhs);
      } else {
        current = stof(rhs) * stof(lhs);
        expression.push(to_string(current));        
      }    
    } else if (postfix_expression[i] == '/') {
      lhs = expression.top();
      expression.pop();
      rhs = expression.top();
      expression.pop();
      if (lhs == "x" || rhs == "x") {
        lhs == "x" ? result = stof(rhs) / result : result *= stof(lhs);
      } else {
        current = stof(rhs) / stof(lhs);
        expression.push(to_string(current));        
      }      
    }
  }
  output << fixed << setprecision(2) << result << endl;
}

string convertToPostfix (stack<string>& expression) {
  stack<string> operators;
  string postfix_expression = "";
  string current;
  while(!expression.empty()) {
    current = expression.top();    
    if (current == "(" || current == ")" || current == "*" || current == "/" || current == "+" || current == "-") {
      if (operators.empty()) {
        operators.push(current);
      } else if (current == "(" || current == ")") {
        if (current == "(") { 
          operators.push(current);
        } else {
          while (!operators.empty() && operators.top() != "(") {
            postfix_expression += operators.top();
            operators.pop();
          }
          operators.pop();
        }
      } else if (precedence(current) > precedence(operators.top())) {
        operators.push(current);
      } else {
        while (!operators.empty() && (precedence(current) <= precedence(operators.top()))) {
          postfix_expression += operators.top();
          operators.pop();
        }
        operators.push(current);
      }
    } else {
      postfix_expression += current;
    }
    expression.pop();
  }

  while(!operators.empty()) {
    postfix_expression += operators.top();
    operators.pop();
  }
  
  return postfix_expression;
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    
    //ifstream input("input3.txt");
    //ofstream output("output.txt");

    string equation = "";
    
    getline(input, equation);

    stack<string> values;
    stack<string> expression;
    int space_Where_Num_Ends;

    //Iterate through each character in the equation. 
    for (int i = 0; i < equation.length(); i++) {
      if (isdigit(equation[i])) {
        space_Where_Num_Ends = equation.substr(i).find(' ');        //We need this to record numbers > 0-9
        if (space_Where_Num_Ends == -1) {                            //This means that we are at the last number (RHS)    
          values.push(equation.substr(i, equation.length() - i));
          break;
        } else {
          values.push(equation.substr(i, space_Where_Num_Ends));
          i += space_Where_Num_Ends - 1;                              //We subtract 1  from i because the for loop increments i by 1. We don't want to skip a value
        }
      } else if (equation[i] != ' ') {                      //Obtain operators, =, and ()
        values.push(equation.substr(i, 1));
      }
    }

    float rhsResult = stof(values.top());
    values.pop();
    values.pop();
  
    while (!values.empty()) {  //We add the values to another stack to evaluate in the correct order
      expression.push(values.top());
      values.pop();
    }

    solveExpression(expression, convertToPostfix(expression), rhsResult, output);
}