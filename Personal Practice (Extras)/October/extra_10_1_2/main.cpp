#include <iostream>
using namespace std;

//This is a program that implements a stack based on a linked list. It holds template values and contains, several functions, such as push, pop, isEmpty, removeAll, and print. The stack can be created as int, string, etc.
template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

//Implemented as linkedlist
template <typename T>
class myStack {
private:
Node<T>* top;  //Head
public:
  myStack() {
    top = nullptr;
  }
  bool isEmpty() { return top == nullptr; }
  bool push(T);
  bool pop();
  void print();
  void removeAll() {
    Node<T>* cu;
    while(top != nullptr) {
      cu = top;
      top = top->next;
      delete cu;
    }
    if (top == nullptr) { cout << "All elements were removed!\n"; }
  }
};

template <typename T>
bool myStack<T>::push(T k) {
  Node<T>* temp = new Node<T>;
  if (temp == nullptr) {
    return false;
  }
  temp->data = k;
  top == nullptr ? temp->next = nullptr : temp->next = top;
  top = temp;
  return true;
}

template <typename T>
bool myStack<T>::pop() {
  if (isEmpty()) {
    return false;
  }
  Node<T>* cu = top;
  top = top->next;
  delete cu;
  return true;
}

template <typename T>
void myStack<T>::print() {
  if (isEmpty()) {
    cout << "The stack is empty!" << endl;
    return;
  }
  Node<T>* cu = top;
  while (cu != nullptr) {
    cout << cu->data << endl;
    cu = cu->next;
  }
}

int main() {
  myStack<string> stack;
  stack.push("Cyrus");
  stack.push("Molly");
  stack.push("Olivia");
  stack.removeAll();
  stack.push("Hayden");
  stack.push("Joe");
  stack.print();
}