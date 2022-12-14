#include <iostream>
#include <stack>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

//Contains the data that we need to add to the priority queue
struct Pair {
  int result;
  string expression;
  Pair* next;
};

//Our priority queue represented as a linked list containing objects of type "Pair"
class PQ {
private:
  Pair* front;
  Pair* rear;
  int size;
public:
  PQ () {
    front = rear = nullptr;
    size = 0;
  }

  bool isEmpty() { return front == nullptr; }

  void enqueue (int res, string exp) {
    Pair* temp = new Pair;
    temp->result = res;
    temp->expression = exp;
    
    if (isEmpty()) {
      front = rear = temp;
    } else if (temp->result < front->result) {
      temp->next = front;
      front = temp;
    } else {
      Pair* cu = front;
      Pair* prev = nullptr;
      while (cu != nullptr && temp->result >= cu->result) {
        prev = cu;
        cu = cu->next;
      }
      temp->next = cu;
      prev->next = temp;
      if (temp->next == nullptr) {
        rear = temp;
      }
    }
    size++;
  }

  void dequeue () {
    if (!isEmpty()) {
      if (front->next == nullptr) {
        Pair* temp = front;
        front = rear = nullptr;
        delete temp;
      } else {
        Pair* temp = front;
        front = front->next;
        delete temp;
      }
    }
    size--;
  }

  Pair* getFront () { return front; }

};

//Function checks to see if the parenthesis in the expression are valid
bool isValid (string str) {
  stack<char> st;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      st.push(str[i]);
    } else if (str[i] == ')') {
      if (st.empty() || st.top() != '(') {
        return false;
      }
      st.pop();
    } else if (str[i] == ']') {
      if (st.empty() || st.top() != '[') {
        return false;
      }
      st.pop();      
    } else if (str[i] == '}') {
      if (st.empty() || st.top() != '{') {
        return false;
      }
      st.pop();
    }
  }
  return st.empty();
}

//Function checks to see if the parenthesis are redundant
bool isRedundant (string str) {
  stack<char> st;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ')' || str[i] == ']' || str[i] == '}') {    
      if (st.top() == '(' || st.top() == '[' || st.top() == '{') {
        return true;
      }
      while (st.top() != '(' && st.top() != '[' && st.top() != '{') {
        st.pop();
      }
      st.pop();
    } else {
      st.push(str[i]);
    }
  }
  return false;
}

//Returns an operator's precedence
int precedence (char c) {
  if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  }
  return 0;
}

//Evaluates the postfix expression and returns the result
int solve_postfix_expression (string exp) {
  stack<int> st;
  int result = 0;

  for (int i = 0; i < exp.length(); i++) {
    if (isdigit(exp[i])) {
      st.push(exp[i] - 48);
    } else {
      int rhs = st.top(); 
      st.pop();
      int lhs = st.top();
      st.pop();

      switch(exp[i]) {
        case '-': st.push(lhs - rhs);
          break;
        case '+': st.push(lhs + rhs);
          break;
        case '*': st.push(lhs * rhs);
          break;
        case '/': st.push(lhs / rhs);
          break;
      }
    }
  }
  return st.top();
}

//Converts an infix expression to a postfix expression
string infix_to_postfix (string exp) {
  string postfix = "";
  stack<char> operators;
  
  for (int i = 0; i < exp.length(); i++) {
    if (isdigit(exp[i])) {
      postfix += exp[i];
    } else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      operators.push(exp[i]);
    } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      while (!operators.empty() && (operators.top() != '(' && operators.top() != '[' && operators.top() != '{')) {
        postfix += operators.top();
        operators.pop();
      }
      operators.pop();
    } else {
      while (!operators.empty() && precedence(exp[i]) <= precedence(operators.top())) {
        postfix += operators.top();
        operators.pop();        
      }
      operators.push(exp[i]);
    }
  }

  while(!operators.empty()) {
    postfix += operators.top();
    operators.pop();    
  }

  return postfix;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
    
  //ifstream input("input3.txt");
  //ofstream output("output.txt");

  string line = ""; 
  PQ priority;
  
  while (getline(input, line)) {
    if (line == "" || !isValid(line) || isRedundant(line)) {
      continue;
    }
    string postFix = infix_to_postfix(line);
    int result = solve_postfix_expression(postFix);
    priority.enqueue(result, line);
  }

  if (priority.isEmpty()) {
    output << "No Valid Expression" << endl;
  } else {
    while (!priority.isEmpty()) {
      output << priority.getFront()->expression << endl;
      priority.dequeue();
    }    
  }
}