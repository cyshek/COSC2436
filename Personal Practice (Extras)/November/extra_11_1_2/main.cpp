#include <iostream>
using namespace std;

//This is a program that creates a binary search tree containing messages and prints them by traversing inorder. Left side contains short messages while right side contains longer messages.
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

    void preOrder(BST* cu) {
      if (cu != nullptr) {
        cout << cu->message << endl;
        preOrder(cu->left);
        preOrder(cu->right);
      }
    }

    void inOrder(BST* cu) {
      if (cu != nullptr) {
        inOrder(cu->left);
        cout << cu->message << endl; 
        inOrder(cu->right);
      }      
    }

    void postOrder(BST* cu) {
      if (cu != nullptr) {
        postOrder(cu->left);
        postOrder(cu->right);
        cout << cu->message << endl;
      }
    }

    BST* insert (BST* cu, string message) {
      if (cu == nullptr) {
        return new BST(message);
      } else if (message.length() < cu->message.length()) {
        cu->left = insert(cu->left, message);
      } else {
        cu->right = insert(cu->right, message);
      }
      return cu;
    }
};

int main() {
  BST tree, *root = nullptr;
  root = tree.insert(root, "Mercyl");
  tree.insert(root, "Cyrus");
  tree.insert(root, "Garryan");
  tree.insert(root, "Joe");
  tree.insert(root, "Xu");
  tree.insert(root, "Jack");
  tree.inOrder(root);
}