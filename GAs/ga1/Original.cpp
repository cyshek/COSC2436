#include "ArgumentManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;


//Each node will hold a decoded id
struct node{
  string id;
  node *next;
};

class linkedlist{
private:
  node *head;
  int sizeOfList;
public:
  linkedlist() { 
    head = nullptr;
    sizeOfList = 0;
  }

  int getSize() { return sizeOfList; }

  node* getHead () { 
    node* cu = head;
    return cu;
  }

  //Inserts decoded ID to the correct position, recursively. We are trying to keep the decoded IDs in ascending order.
  void insert(string data, node* cu) {
    if (head == nullptr) {
      node *temp = new node;
      temp->id = data;
      temp->next = head;
      head = temp;
      sizeOfList++;
      return;
    }   
    if (cu == nullptr) {
      return;
    }
    if (stoll(data) > stoll(cu->id) && cu->next == nullptr) {
      node* temp = new node;
      temp->id = data;
      temp->next = nullptr;
      cu->next = temp;
      sizeOfList++;
      return;
    }
    else if (stoll(data) < stoll(cu->id) && cu == head) {
      node* temp = new node;
      temp->id = data;
      temp->next = head;
      head = temp;
      sizeOfList++;
      return;
    }
    else if (stoll(data) > stoll(cu->id) && stoll(data) < stoll(cu->next->id)) {
      node* temp = new node;
      temp->id = data;
      temp->next = cu->next;
      cu->next = temp;
      sizeOfList++;
      return;
    }
    else {
      insert(data, cu->next);
    }
  }

  //Decides if the ID is a duplicate, recursively. If it is, add to the guilty list, else, add to innocent
  bool findMatchingIDs (node* cu, string data) {
    if (cu == nullptr) {
      return false;
    }
    if (cu->id == data) {
      node* cu = head;
      deleteValue(data, cu, nullptr);
      return true;
    }
    return findMatchingIDs(cu->next, data);
  }

  //Delete the duplicate ID recursively
  void deleteValue (string val, node* curr, node* prev) {
    if (curr == nullptr) {
      return;
    }
    if (curr->id.find(val) != string::npos) {
      if (curr == head) {
        node* temp = curr;
        curr = curr->next;
        head = curr;
        delete temp;
        sizeOfList--;
      } else if (curr->next == nullptr) {
        prev->next = nullptr;
        delete curr;
        sizeOfList--;
        return;
      } else {
        prev->next = curr->next;
        node* temp = curr;
        curr = curr->next;
        delete temp;
        sizeOfList--;
      }
    } else {
      deleteValue(val, curr->next, curr);
    }
  }

  //Print the linkedlist recursively
  void print(node* cu, ostream& out) {
    if (cu == nullptr) {
      return;
    }
    out << cu->id << endl;
    print(cu->next, out);
  }
};

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream out(am.get("output"));
  
  //ifstream input("input11.txt");
  //ofstream output("output11.txt");
  string inStr, idStr;
  int parenthesisInStack;
  stack<char> stack;
  queue<char> queue;
  linkedlist innocent;
  linkedlist guilty;
  
 while(getline(input, inStr)){
  
  //Clean up the string
  inStr.erase(remove(inStr.begin(), inStr.end(), ' '), inStr.end());
  inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
  inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());
  
  //ignore empty lines and ignore "Bar#"
  if (inStr.find("Bar") != string::npos || inStr == "") {
    continue;
  }
  
  //Reset since we are reading a new string
  parenthesisInStack = 0;
  idStr = "";

  //Decode the current string and store correct string into idStr
  for(int i = 0; i < inStr.length(); i++){
    if(parenthesisInStack == 0 && isdigit(inStr[i])){
      idStr += inStr[i];
    }
    else if(inStr[i] == '('){
      stack.push(inStr[i]);
      parenthesisInStack++;
    }
    else if(parenthesisInStack > 0 && isdigit(inStr[i])){
      stack.push(inStr[i]);
    }
    else if(parenthesisInStack > 1 && inStr[i] == ')'){
      while(stack.top() != '(') {
        queue.push(stack.top());
        stack.pop();
      }
      stack.pop();      //delete '(' from the stack
      parenthesisInStack--;

      while (!queue.empty()) {
        stack.push(queue.front());
        queue.pop();
      }
    }
    else {
      while(!stack.empty()) {
        if (stack.top() == '(') {
          stack.pop();
        } else {
          idStr += stack.top();
          stack.pop();          
        }
      }
      parenthesisInStack--;
    }
  }

  //insert idString into your linkedList 
  if (innocent.findMatchingIDs(innocent.getHead(), idStr)) {
    guilty.insert(idStr, guilty.getHead());
  } else {
    innocent.insert(idStr, innocent.getHead());
  }
} 
 //Print the lists if they aren't empty 
 if (guilty.getSize() > 0) {
   out << "Guilty:\n";
   guilty.print(guilty.getHead(), out);  
 }
  
 if (innocent.getSize() > 0) {
   out << "Innocent:\n";
   innocent.print(innocent.getHead(), out);  
 }
}
