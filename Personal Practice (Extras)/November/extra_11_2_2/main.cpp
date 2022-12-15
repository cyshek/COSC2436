#include <iostream>
using namespace std;

//This is a program that inserts, removes, and prints the nodes in a BST inorderly. Calculates the minimum node's value. Also calculates the size, the height, and searches for a key in the tree. Has a function to get the depth of a node.
struct node{
    node *left;
    int data;
    node *right;
    node(int _data): data(_data), left(nullptr), right(nullptr){}
};

class tree {
private:
    node *root;
public:
    tree() { root = nullptr; };
    bool isBST(node *);
    node* insert(int, node*);
    node* remove(int, node*); 
    bool search(int, node*);
    node *getRoot() { return root; };
    void reverseOrder(node *);
    int count(node *);
    int getDepth(int, node*);
    int maxDepth(node*);
    node* minValue(node*);
    void inOrderTraversal(node*);
    void preOrderTraversal(node*);
    void postOrderTraversal(node*);
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

node* tree::remove(int key, node* cu) {
  if (!root || !cu) {
    return nullptr;
  } else if (key < cu->data) {
    cu->left = remove(key, cu->left);
  } else if (key > cu->data) {
    cu->right = remove(key, cu->right);
  } else {
    if (!cu->left && !cu->right) {
      return nullptr;
    } else if (!cu->left) {
      node* temp = cu->right;
      delete cu;
      return temp;
    } else if (!cu->right) {
      node* temp = cu->left;
      delete cu;
      return temp;
    } else {
      node* temp = minValue(cu->right);
      cu->data = temp->data;
      cu->right = remove(temp->data, cu->right);
    }
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
    return 1 + max(maxDepth(cu->left), maxDepth(cu->right));
  }
}

node* tree::minValue(node* n) {
  node* cu = n;
  while(cu && cu->left) {
    cu = cu->left;
  }
  return cu;
}

void tree::inOrderTraversal(node* cu){
    if (cu){
        inOrderTraversal(cu->left);
        cout << cu->data << " ";
        inOrderTraversal(cu->right);
    }
}

void tree::preOrderTraversal(node* cu) {
  if (cu) {
    cout << cu->data << " ";
    preOrderTraversal(cu->left);
    preOrderTraversal(cu->right);
  }
}

void tree::postOrderTraversal(node* cu) {
  if (cu) {
    postOrderTraversal(cu->left);
    postOrderTraversal(cu->right);
    cout << cu->data << " ";
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
  bst.insert(4, bst.getRoot());
  bst.insert(2, bst.getRoot());
  bst.insert(1, bst.getRoot());
  bst.insert(6, bst.getRoot());
  bst.insert(3, bst.getRoot());
  bst.insert(5, bst.getRoot());
  bst.insert(7, bst.getRoot());
  bst.remove(2, bst.getRoot());
  bst.remove(4, bst.getRoot());
  bst.remove(7, bst.getRoot());
  bst.remove(3, bst.getRoot());
  bst.inOrderTraversal(bst.getRoot());
  //cout << "\n" << bst.count(bst.getRoot());
  //cout << "\n" << bst.maxDepth(bst.getRoot()) << endl;
}