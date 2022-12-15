#include <iostream>
#include "listofcars.h"

using namespace std;

//This program adds a car node to the beginning of the car list. Also checks if the list is empty and creates a new head. The list is printed after the nodes are added.

listofcars::listofcars() {    //Constructor
  head = 0;
}

bool listofcars::isempty() {
  if (head == 0) {
    return true;
  } else {
    return false;
  }
}

void listofcars::addatbeg(int a, float b) {
  //1. Create a car
  //2. Fill it with values
  //3. Link/ update pointers
  if (isempty()) {
    head = new car;
    head->year = a;
    head->price = b;
    head->next = nullptr;
  } else {
    car* temp = new car;
    temp->year = a;
    temp->price = b;
    temp->next = head;
    head = temp;
  }
}

void listofcars::print() {
  while (head != nullptr) {
    cout << "Year is " << head->year << " and price is " << head->price << endl;
    head = head->next;
  }
}

int main() {
  listofcars lexus;
  lexus.addatbeg(2010, 105.55);
  lexus.addatbeg(2022, 1367.55);
  lexus.print();
  return 0;
}