#include <iostream>
#include "listofcars.h"

using namespace std;

//This program adds a car node at the end of the car list. Also checks if the list is empty and creates a new head. The list is printed after the nodes are added.

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

void listofcars::addatend(int a, float b) {
  if (isempty()) {
    head = new car;
    head->year = a;
    head->price = b;
    head->next = nullptr;
  } else {
    car *temp = new car;
    temp->year = a;
    temp->price = b;
    temp->next = nullptr;
    car* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = temp;
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
  lexus.addatend(2010, 105.55);
  lexus.addatend(2022, 1367.55);
  lexus.print();
  return 0;
}