#include <iostream>
using namespace std;


//This is a program that implements a queue as a linkedlist based on a template. We use enqueue to add elements, dequeue to remove elements, and we print the contents of the queue recursively.
template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

template <typename T>
class qall {
private:
  Node<T>* front;
  Node<T>* back;
  int size;
public:
  qall() {
    front = back = nullptr;
    size = 0;
  }

  bool isempty() { return size == 0; }

  void enqueue (T data) {
      Node<T>* temp = new Node<T>;
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
      Node<T>* temp = front;
      delete temp;
      front = back = nullptr;
    } else {
      Node<T>* temp = front;
      front = front->next;
      delete temp;
    }
    size--;
  }

  Node<T>* getFront () { return front; }
  
  void print (Node<T>* temp) {
    if (temp == nullptr) { return; }
    cout << temp->data << endl;
    print(temp->next);
  }
};

int main() {
  qall<string> myqueue;
  myqueue.enqueue("Cyrus");
  myqueue.enqueue("Jill");
  myqueue.enqueue("Mercy");
  myqueue.dequeue();
  myqueue.enqueue("Garry");
  myqueue.enqueue("Google");
  myqueue.print(myqueue.getFront());
  
  return 0;
}