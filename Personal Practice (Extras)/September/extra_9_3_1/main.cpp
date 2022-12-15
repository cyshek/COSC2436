#include <iostream>
using namespace std;

//This is a program that creates a circular linkedlist and prints the first 8 letters. The print function is invoked recursively and the parameter for the number of elements to be printed can be changed.

struct Node {
 char letter;
  Node* next;
};

class linkedlist {
private:
Node* head;
Node* tail;
int size;
public:
  linkedlist () {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  void printList () {
    Node* curr = head;
    while (curr != nullptr) {
      cout << curr->letter << endl;
      curr = curr->next;
    }
  }

  void addToEnd (char c) {
    Node* temp = new Node;
    temp->letter = c;
    if (head == nullptr) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = temp;
    }
    size++;
  }

  void makeCircular () {
    tail->next = head;
  }

  void disconnect () {
    tail->next = nullptr;
  }

  void printCircular (int numOfElementsToPrint) {
    Node* curr = head;
    printCircularRec(numOfElementsToPrint, curr);
  }

  void printCircularRec(int n, Node* curr) {
    if (n <= 0) {
      return;
    } else {
      cout << curr->letter << endl; 
      printCircularRec(n - 1, curr->next);
    }
  }
  int getSize () { return size; }
};
int main() {
  linkedlist list;
  list.addToEnd('C');
  list.addToEnd('Y');
  list.addToEnd('R');
  list.addToEnd('U');
  list.addToEnd('S');
  list.makeCircular();
  list.printCircular(8);
}
