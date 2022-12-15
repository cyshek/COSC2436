#include <iostream>
using namespace std;

//Basic linkedlist represented as a necklace that contains several pearls. Adds pearls to the end of the necklace and prints the colors of each pearl.
struct Pearl {
int color;
Pearl* hole;
};

class necklace {
private:
  Pearl *head;
public: 
  necklace() {
    head = nullptr;
  }
  void addpearl(int c) {
    if (head == nullptr) {
      head = new Pearl;
      head->color = c;
      head->hole = nullptr;
    } else {      
      Pearl* p;
      Pearl* last = head;
      while (last->hole != nullptr) {
        last = last->hole;
      }
      p = new Pearl;
      p->color = c;
      last->hole = p;
      p->hole = nullptr;
    }

  }
  void print() {
    while(head != nullptr) {
      cout << head->color << endl;
      head = head->hole;
    }
  }
};

int main() {
  necklace mine;
  mine.addpearl(1);
  mine.addpearl(5);
  mine.addpearl(982);
  mine.print();
  return 0;
}