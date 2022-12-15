#include <iostream>
using namespace std;


//This is a program that implements a queue of type integer as a linkedlist. We use enqueue to add elements, dequeue to remove elements, and we print the contents of the queue recursively.
struct Node {
  int data;
  Node* next;
};

class qall {
private:
  Node* front;
  Node* back;
  int size;
public:
  qall() {
    front = back = nullptr;
    size = 0;
  }

  bool isempty() { return size == 0; }

  void enqueue (int data) {
      Node* temp = new Node;
      //assert(temp) checks if temp is null
      temp->data = data;
      temp->next = nullptr;
    if (isempty()) {
      front = back = temp;
    } else {
      back->next = temp;
      back = temp;
    }
    size++;
  }

  void dequeue () {
    if (isempty()) {
      cout << "Queue is empty!!!" << endl;
      return;
    } else if (size == 1) {
      Node* temp = front;
      delete temp;
      front = back = nullptr;
    } else {
      Node* temp = front;
      front = front->next;
      delete temp;
    }
    size--;
  }

  Node* getFront () { return front; }
  
  void print (Node* temp) {
    if (temp == nullptr) { return; }
    cout << temp->data << endl;
    print(temp->next);
  }
};

int main() {
  qall myqueue;
  myqueue.enqueue(1);
  myqueue.enqueue(2);
  myqueue.enqueue(3);
  myqueue.dequeue();
  myqueue.enqueue(4);
  myqueue.print(myqueue.getFront());
  return 0;
}