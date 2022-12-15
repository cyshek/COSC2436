#include <iostream>
using namespace std;

//Linkedlist is ONLY identified by head. Must have head.
struct car {
  int year;
  float price;
  car* next;
};

class listofcars {
private:
  car* head;
public:
  listofcars();
  bool isempty();
  void addatbeg(int, float);
  void addatend(int, float);
  void addmiddlebyvalue(int, float, int value);
  void addmiddlebyposition(int, float, int pos);
  //delete
  //search
  void print();
};