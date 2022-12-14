#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

struct Node {
  string path;
  int data;
  Node* left;
  Node* right;
  Node(int _data, string _path) : data(_data), path(_path), left(nullptr), right(nullptr) {}
};

class BST {
  private:
    Node* root;
  public:
    BST () { root = nullptr; }
    Node* getRoot() { return root; }
    
    void preOrder(Node* cu, ostream& output) {
      if (cu) {
        output << "[" << cu->path << "]" << " " << cu->data << endl;
        preOrder(cu->left, output);
        preOrder(cu->right, output);
      }
    }

    Node* insert (Node* cu, int data, string path) {
      if (!root) {
        Node* temp = new Node(data, path);
        root = temp;
      } 
      if (!cu) {
        Node* temp = new Node(data, path);
        cu = temp;
        return cu;
      } else if (data < cu->data) {
        path = path + "l";
        cu->left = insert(cu->left, data, path);
      } else {
        path = path + "r";
        cu->right = insert(cu->right, data, path);
      }
      return cu;
    }
};

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

  //ifstream input("input3.txt");
  //ofstream output("output.txt");

  BST tree;
  int num;
  
  while (input >> num) {
    tree.insert(tree.getRoot(), num, "x");
  }
  
  tree.preOrder(tree.getRoot(), output);
}
