#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

struct Pair {
  float time;
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

  bool isEmpty() { return size == 0;}

  void enqueue (float t, string s) {
    Pair* temp = new Pair;
    temp->time = t;
    temp->content = s;
    if (isEmpty()) {
      front = back = temp;
    } else {
      Pair* cu = front;
      while (cu != nullptr) {
        if (t < cu->time && cu == front) {
          temp->next = front;
          front = temp;
          break;
        } else if (t >= cu->time && cu->next == nullptr) {
          back->next = temp;
          back = temp;
          break;
        } else if (t >= cu->time && t < cu->next->time) {
          temp->next = cu->next;
          cu->next = temp;
          break;
        }
        cu = cu->next;
      }
    }
    size++;
  }

  void print (ostream& output) {
    Pair* cu = front;
    while (cu != nullptr) {
      output << cu->content << endl;
      cu = cu->next;
    }
  }
};

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
    
  //ifstream input("inputTest.txt");
  //ofstream output("output.txt");

  string line = "";
  float time = 0.0;

  PQ pq;
  
  while (getline(input, line)) {
    if (line != "") {
      for (int i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
          time = stof(line.substr(i, line.length() - i));
          line = line.substr(0, i - 1);
        }
      }
      pq.enqueue(time, line);
    }
  }
  pq.print(output);
}