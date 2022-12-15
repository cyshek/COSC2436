#include <iostream>
using namespace std;

//Delete every other node in a ciruclar linkedlist. Add characters using "addToEnd" function and print the first n characters recursively.
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

  void printCircular (int timesToPrint) {
    Node* curr = head;
    printCircularRec(timesToPrint, curr);
  }

  void printCircularRec(int n, Node* curr) {
    if (n <= 0) {
      return;
    } else {
      cout << curr->letter << endl; 
      printCircularRec(n - 1, curr->next);
    }
  }

  void deleteEveryOtherNode () {
    Node* curr = head;
    while (true) {
      curr->next = curr->next->next;
      curr = curr -> next;
      if (curr == head || curr->next == head) {
        break;
      }
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
  list.deleteEveryOtherNode();
  list.printCircular(8);
}

