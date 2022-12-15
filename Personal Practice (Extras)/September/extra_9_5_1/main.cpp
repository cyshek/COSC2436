#include <iostream>
using namespace std;

//This is a program that creates a singly linked list and reverses it. The program prints out the reversed list recursively.
struct Node {
 int data;
 Node* next;
};

class List {
private:
Node* head;
Node* tail;
public:
    List () { head = tail = 0; }
    void printList(Node*cu) {
        if (cu == nullptr) {
            return;
        }
        cout << cu->data << endl;
        return printList(cu->next);
    }
    
    void add (int data) {
        Node* temp = new Node;
        temp->data = data;
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    void reverse () {
        Node* cu = head;
        Node* prev = nullptr;
        Node* temp = nullptr;
        
        while (cu != nullptr) {
            temp = cu->next;
            cu->next = prev;
            prev = cu;
            cu = temp;
        }
        head = prev;
    }
    
    Node* getHead() {
        Node* cu = head;
        return cu;
    }
};

int main()
{
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.reverse();
    list.printList(list.getHead());

    return 0;
}
