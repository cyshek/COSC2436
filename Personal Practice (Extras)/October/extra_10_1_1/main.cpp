#include <iostream>
using namespace std;

//This is a program that implements a stack based on a linked list. It holds integer values and contains, several functions, such as push, pop, isEmpty, removeAll, and print.
struct Node {
  int data;
  Node* next;
};

//Implemented as linkedlist
class myStack {
private:
Node* top;  //Head
public:
  myStack () {
    top = nullptr;
  }
  bool isEmpty() { return top == nullptr; }
  bool push(int);
  bool pop();
  void print();
  void removeAll() {
    Node* cu;
    while(top != nullptr) {
      cu = top;
      top = top->next;
      delete cu;
    }
    if (top == nullptr) { cout << "All elements were removed!\n"; }
  }
};

bool myStack::push(int k) {
  Node* temp = new Node;
  if (temp == nullptr) {
    return false;
  }
  temp->data = k;
  top == nullptr ? temp->next = nullptr : temp->next = top;
  top = temp;
  return true;
}

bool myStack::pop() {
  if (isEmpty()) {
    return false;
  }
  Node* cu = top;
  top = top->next;
  delete cu;
  return true;
}

void myStack::print() {
  if (isEmpty()) {
    cout << "The stack is empty!" << endl;
    return;
  }
  Node* cu = top;
  while (cu != nullptr) {
    cout << cu->data << endl;
    cu = cu->next;
  }
}

int main() {
  myStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.removeAll();
  stack.push(4);
  stack.push(6);
  stack.pop();
  stack.print();
}
