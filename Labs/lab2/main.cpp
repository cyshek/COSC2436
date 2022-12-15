#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ArgumentManager.h"
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

template <typename T>
class linkedlist {
private:
  Node<T>* head;
  int size;
public:
  linkedlist();
  ~linkedlist();
  bool isEmpty() {return head == nullptr;}
  int getSize() {return size;}
  void addAtHead(T value);
  void addAtTail(T value);
  void removeAtHead();
  void removeAtTail();
  void print(ostream& out);
};

template <typename T>
linkedlist<T>::linkedlist() {
  head = nullptr;
  size = 0;
}

template <typename T>
linkedlist<T>::~linkedlist() {
  Node<T>* cu = head;
  while (cu != nullptr) {
    Node<T>* temp = cu;
    cu = cu->next;
    delete temp;
  }
}

template <typename T>
void linkedlist<T>::addAtTail(T value) {
  Node<T>* temp = new Node<T>;
  temp->data = value;
  temp->next = nullptr;

  Node<T>* cu = head;
  if (cu == nullptr) {
    head = temp;
  } else {
    while (cu->next != nullptr) {
      cu = cu->next;
    }
    cu->next = temp;
  }
  size++;
}

template <typename T>
void linkedlist<T>::removeAtTail() {
  Node<T>* cu = head;
  Node<T>* prev = nullptr;
  if (cu == nullptr) {
    return;
  } else if (cu->next == nullptr) {
    head = nullptr;
  } else {
    while (cu->next != nullptr) {
      prev = cu;
      cu = cu->next;
    }
    prev->next = nullptr;
    delete cu;
    size--;
  }
}

template<typename T>
void linkedlist<T>::addAtHead(T value) {
  Node<T>* temp = new Node<T>;
  temp->data = value;
  temp->next = head;
  head = temp;
  size++;
}

template<typename T>
void linkedlist<T>::removeAtHead() {
  Node<T>* temp = head;
  head = head->next;
  size--;
  delete temp;
}

template<typename T>
void linkedlist<T>::print(ostream& out) {
  Node<T>* cu = head;
  while(cu != nullptr) {
    if (cu->next == nullptr) {
      out << cu->data;
      return;
    }
    out << cu->data << " ";
    cu = cu->next;
  }
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    
    //ifstream input("input3.txt");
    //ofstream output("output.txt");
  
    string t;
    string tt;
    vector<string> words;
    linkedlist<string> list1;
    linkedlist<int> list2;
    linkedlist<char> list3;
  
    getline(input, t);
    t.erase(remove(t.begin(), t.end(), '\n'), t.end());
    t.erase(remove(t.begin(), t.end(), '\r'), t.end());
    
    if (t == "string") {
      while (getline(input, tt)) {
        tt.erase(remove(tt.begin(), tt.end(), '\n'), tt.end());
        tt.erase(remove(tt.begin(), tt.end(), '\r'), tt.end());             
        words.push_back(tt);
      }
        for (int i = 1; i < words.size(); i++) {
        if (words[0] == "head") {
          if (words[i] == "remove tail") {
            list1.removeAtTail();
          } else if (words[i] == "remove head") {
            list1.removeAtHead();
          } else {
            list1.addAtHead(words[i]);
          }
        } else if (words[0] == "tail") {
          if (words[i] == "remove tail") {
            list1.removeAtTail();
          } else if (words[i] == "remove head") {
            list1.removeAtHead();
          } else {
            list1.addAtTail(words[i]);
          }  
        }
        }
    } else if (t == "int") {
      while (getline(input, tt)) {
        tt.erase(remove(tt.begin(), tt.end(), '\n'), tt.end());
        tt.erase(remove(tt.begin(), tt.end(), '\r'), tt.end());             
        words.push_back(tt);
      }
        for (int i = 1; i < words.size(); i++) {
        if (words[0] == "head") {
          if (words[i] == "remove tail") {
            list2.removeAtTail();
          } else if (words[i] == "remove head") {
            list2.removeAtHead();
          } else {
            list2.addAtHead(stoi(words[i]));
          }
        } else if (words[0] == "tail") {
          if (words[i] == "remove tail") {
            list2.removeAtTail();
          } else if (words[i] == "remove head") {
            list2.removeAtHead();
          } else {
            list2.addAtTail(stoi(words[i]));
          }  
        }
        }     
    } else if (t == "char") {
      while (getline(input, tt)) {
        tt.erase(remove(tt.begin(), tt.end(), '\n'), tt.end());
        tt.erase(remove(tt.begin(), tt.end(), '\r'), tt.end());             
        words.push_back(tt);
      }
        for (int i = 1; i < words.size(); i++) {
        if (words[0] == "head") {
          if (words[i] == "remove tail") {
            list3.removeAtTail();
          } else if (words[i] == "remove head") {
            list3.removeAtHead();
          } else {
            list3.addAtHead(words[i][0]);
          }
        } else if (words[0] == "tail") {
          if (words[i] == "remove tail") {
            list3.removeAtTail();
          } else if (words[i] == "remove head") {
            list3.removeAtHead();
          } else {
            list3.addAtTail(words[i][0]);
          }  
        }
        }       
    }
    
    if (list1.getSize() > 0) {
      list1.print(output);
    } else if (list2.getSize() > 0) {
      list2.print(output);
    } else if (list3.getSize() > 0) {
      list3.print(output);
    } else {
      output << "";
    }
  
    input.close();
    output.close();
}