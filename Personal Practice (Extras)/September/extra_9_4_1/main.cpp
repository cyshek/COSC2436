#include <iostream>
using namespace std;

//This is a program that creates a doubly linked list with insertion and deletion functions. Also prints the list forwards and backwards to show that the previous pointers are working. The size of the list is also printed.
struct Node {
  Node* next;
  Node* prev;
  int number;
};

class LinkedList {
private:
Node* head;
Node* tail;
int size;
public:
LinkedList();
void printListRec(Node*);
void insert(int, int);
void deleteNum(int);
Node* getHead() {return head;}
int getSize() {return size;}
void printforback() {
  Node* cu = head;
  while (cu != nullptr) {
    cout << cu->number << endl;
    cu = cu->next;
  }
  cu = tail;
  while (cu != nullptr) {
    cout << cu->number << endl;
    cu = cu->prev;
  }
}
};

LinkedList::LinkedList() {
  head = tail = nullptr;
  size = 0;
}

void LinkedList::printListRec(Node* cu) {
  if (cu == nullptr) {
    return;
  } 
  cout << cu->number << endl;
  printListRec(cu->next);
}

void LinkedList::insert(int num, int index) {
  Node* cu = head;
  Node* temp = new Node;
  temp->number = num;
  if (index == 0) {
    if (head == nullptr) {
      head = tail = temp;
    } else {
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
  } else if (index == size) {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  } else {
    int i = 0;
    while (cu != nullptr && i != index - 1) {
      cu = cu->next;
      i++;
    }
    if (cu == nullptr) {
      return;
    }
    temp->next = cu->next;
    cu->next->prev = temp;
    temp->prev = cu;
    cu->next = temp;
  }
  size++;
}

void LinkedList::deleteNum(int val) {
  Node* cu = head;
  Node* temp;
  Node* prev = nullptr;
  while (cu != nullptr) {
    if (cu->number == val) {
      if (cu == head) {
        temp = cu;
        cu = cu->next;
        head = cu;
        head->prev = nullptr;
        delete temp;
        size--;
      } else if (cu == tail) {
        prev->next = nullptr;
        tail = prev;
        delete cu;
        size--;
        return;
      } else {
        prev->next = cu->next;
        cu->next->prev = prev;
        temp = cu;
        cu = cu->next;
        delete temp;
        size--;
      }
    } else {
      prev = cu;
      cu = cu->next;
    }
  }
}

int main() {
  LinkedList list;
  list.insert(1, 0);
  list.insert(2, 1);
  list.insert(3, 2);
  list.insert(4, 3);
  list.insert(5, 4);
  list.deleteNum(3);
  //list.printListRec(list.getHead());
  list.printforback();
  cout << "\nSize: " << list.getSize() << endl;
}