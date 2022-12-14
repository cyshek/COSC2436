#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include "ArgumentManager.h"
using namespace std;

struct Pair {
  int priority;
  string content;
  Pair* next;
};

class PQ {
private:
  Pair* front;
  Pair* back;
  int size;
public:
  PQ () {
    front = back = nullptr;
    size = 0;
  }

  bool isEmpty() { return front == nullptr;}

  void enqueue (int t, string s) {
    Pair* temp = new Pair;
    temp->priority = t;
    temp->content = s;
    if (isEmpty()) {
      front = back = temp;
    } else {
      Pair* cu = front;
      Pair* prev = nullptr;
      if (t < cu->priority) {
        temp->next = front;
        front = temp;
        size++;
        return;
      }
      while (cu != nullptr && t >= cu->priority) {
        prev = cu;
        cu = cu->next;
      }
      prev->next = temp;
      temp->next = cu;
    }
    size++;
  }

  void dequeue () {
    if (isEmpty()) {
      return;
    } else if (front->next == nullptr) {
      front = back = nullptr;
    } else {
      Pair* temp = front;
      front = front->next;
      delete temp;
    }
    size--;
  }

  Pair* getFront () { return front; }
};

class BST {
  private:
    BST* left;
    BST* right;
    string message;
  public:
    BST () {
      left = right = nullptr;
      message = "";
    }

    BST (string m) {
      left = right = nullptr;
      message = m;
    }

    void preOrder(BST* cu, ostream& output) {
      if (cu != nullptr) {
        output << cu->message << endl;
        preOrder(cu->left, output);
        preOrder(cu->right, output);
      }
    }

    void inOrder(BST* cu, ostream& output) {
      if (cu != nullptr) {
        inOrder(cu->left, output);
        output << cu->message << endl; 
        inOrder(cu->right, output);
      }      
    }

    void postOrder(BST* cu, ostream& output) {
      if (cu != nullptr) {
        postOrder(cu->left, output);
        postOrder(cu->right, output);
        output << cu->message << endl;
      }
    }

    BST* insert (BST* cu, string message) {
      if (cu == nullptr) {
        return new BST(message);
      } else if (message.length() == cu->message.length()) {
        cu->message = message;
      } else if (message.length() < cu->message.length()) {
        cu->left = insert(cu->left, message);
      } else {
        cu->right = insert(cu->right, message);
      }
      return cu;
    }
};

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
    
  //ifstream input1("input.txt");
  //ofstream output("output.txt");

  string line = "";
  string command = "";
  string priority = "";
  string treeTraversal = "";
  string fixed = "";
  
  PQ commands;
  queue<string> messages;
  BST tree, *root = nullptr;
  
  while(getline(input, line)) {
    command = line.substr(0, line.find('('));
    line = line.substr(line.find('(') + 1);
    priority = line.substr(0, line.find(')'));
    line.erase(remove(line.begin(), line.end(), ')'), line.end());
    if (command == "Inorder" || command == "Preorder" || command == "Postorder") {
      treeTraversal = command;
      break;
    }
    commands.enqueue(stoi(priority), command);     
  }
  
  while(!commands.isEmpty()) {
    line = commands.getFront()->content;
    command = line.substr(0, line.find(':'));
    if (command == "BST") {
      if (!messages.empty()) {
        string str = "";
        str = messages.front();
        messages.pop();
        if (root == nullptr) {
          root = tree.insert(root, str);
        } else {
          tree.insert(root, str);
        }
      }
    }
    
    line = line.substr(line.find('[') + 1);
    line = line.substr(0, line.find(']'));

    if (command == "DECODE") {
      messages.push(line);
    } else if (command == "REPLACE") {
      if (!messages.empty()) {
        fixed = messages.front();
        messages.pop();
        replace(fixed.begin(), fixed.end(), line[0], line[2]);
        messages.push(fixed);        
      }
    } else if (command == "SWAP") {
      if (!messages.empty()) {
        fixed = messages.front();
        messages.pop();
        string newStr = "";

        for (int i = 0; i < fixed.length(); i++) {
          if (fixed[i] == line[0]) {
            newStr += line[2];
          } else if (fixed[i] == line[2]) {
            newStr += line[0];
          } else {
            newStr += fixed[i];
          }
        }
        messages.push(newStr);        
      }
    } else if (command == "REMOVE") {
      if (!messages.empty()) {
        fixed = messages.front();
        messages.pop();
        fixed.erase(remove(fixed.begin(), fixed.end(), line[0]), fixed.end());
        messages.push(fixed);        
      }
    } else if (command == "ADD") {
      if (!messages.empty()) {
        fixed = messages.front();
        messages.pop();
        string newStr = "";

        for (int i = 0 ; i < fixed.length(); i++) {
          if (fixed[i] == line[0]) {
            newStr += line[0];
            newStr += line[2];
          } else {
            newStr += fixed[i];
          }
        }
        messages.push(newStr);
        
      }
    }
    commands.dequeue();
  }

  if (treeTraversal == "Inorder") {
    tree.inOrder(root, output);
  } else if (treeTraversal == "Preorder") {
    tree.preOrder(root, output);
  } else if (treeTraversal == "Postorder") {
    tree.postOrder(root, output);
  }
}
