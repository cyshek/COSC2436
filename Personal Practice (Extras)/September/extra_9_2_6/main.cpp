#include <iostream>
using namespace std;

//This program deletes the letter node at the end of the linkedlist consisting of words. Prints each node recursively in the linkedlist.
struct Node {
  char letter;
  Node* next;
};

//Represents the words
class LinkedList {
private:
  Node* head;
  Node* tail;
public: 
  LinkedList() { head=tail=0;}
  void addatend (char l) {
    Node* temp;
    temp = new Node;
    temp->letter = l;
    temp->next = nullptr;
    if (head == nullptr) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }
  }

  void deletefromend() {
    Node* temp = tail;
    cout << temp->letter << " was deleted\n"<< endl;
    Node* current = head;
    while (current->next != temp) {
      current = current->next;
    }
    current->next = 0;
    tail = current;
    delete temp;
  }

  void print() {
    Node* current = head;
    printrec(current);
  }

  //Print the nodes in a linked list recursively
  void printrec(Node *cu) {
    if (cu == nullptr) {
      return;
    } else {      
      cout << cu->letter << endl;
      printrec(cu->next);
    }
  }
};

int main() {
  LinkedList words;
  words.addatend('C');
  words.addatend('Y');
  words.addatend('R');
  words.addatend('U');
  words.addatend('S');
  words.deletefromend();
  words.print();
}