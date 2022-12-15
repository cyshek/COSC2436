#include <iostream>
using namespace std;

//This is a program that builds and prints a BST inorderly. Also calculates the size, the height and searches for a key in the tree. Has a function to get the depth of a node.
struct node{
    node *left;
    int data;
    node *right;
    node(int _data): data(_data), left(nullptr), right(nullptr){}
};

class tree{
private:
    node *root;
public:
    tree() { root = nullptr; };
    bool isBST(node *);
    node* insert(int, node *);
    void remove(); 
    bool search(int, node*);
    node *getRoot() { return root; };
    void reverseOrder(node *);
    int count(node *);
    int getDepth(int, node*);
    int maxDepth(node*);
    void inOrderTraversal(node*);
    void printLeaves(node *);
};

node* tree::insert(int _data, node *cu) {
    if (root == nullptr) {
        node *temp = new node(_data);
        root = temp;
    }
    if (!cu){
        node *temp = new node(_data);
        cu = temp;
        return cu;
    }
    else if (_data < cu->data) {
        cu->left = insert(_data, cu->left);
    } else {
        cu->right = insert(_data, cu->right);
    }
    return cu;
}

int tree::count (node* cu) {
  if (!root || !cu) {
    return 0;
  }
  return count(cu->left) + 1 + count(cu->right);
}

int tree::getDepth(int key, node* cu) {
  if (!root || !cu) {
    return 0;
  } else if (cu->data == key) {
    return 0;
  } else if (key > cu->data) {
    return getDepth(key, cu->right) + 1;
  } else {
    return getDepth(key, cu->left) + 1;
  }
}

int tree::maxDepth(node* cu) {
  if (!root || !cu) {
    return 0;
  } else {
    int lhs = maxDepth(cu->left);
    int rhs = maxDepth(cu->right);
    if (lhs > rhs) { 
      return lhs;
    } else {
      return rhs + 1;
    }
  }
}
void tree::inOrderTraversal(node* cu){
    if (cu){
        inOrderTraversal(cu->left);
        cout << cu->data << " ";
        inOrderTraversal(cu->right);
    }
}

bool tree::search(int val, node* cu) {
  if (!root || !cu) {
    return false;
  } else if (cu->data == val) {
    return true;
  } else if (val < cu->data) {
    return search(val, cu->left);
  } else {
    return search(val, cu->right);
  }
}

int main() {
  tree bst;
  bst.insert(50, bst.getRoot());
  bst.insert(30, bst.getRoot());
  bst.insert(20, bst.getRoot());
  bst.insert(40, bst.getRoot());
  bst.insert(70, bst.getRoot());
  bst.insert(60, bst.getRoot());
  bst.insert(80, bst.getRoot());
  bst.insert(10, bst.getRoot());
  bst.inOrderTraversal(bst.getRoot());
  cout << "\n" << bst.count(bst.getRoot());
  cout << "\n" << bst.maxDepth(bst.getRoot()) << endl;
}