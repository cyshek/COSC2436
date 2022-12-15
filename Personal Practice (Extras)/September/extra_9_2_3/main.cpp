
#include <iostream>
#include "listofcars.h"

using namespace std;

//This program inserts a car node to the list of cars after a given value. The program also iterates through the elements and prints each one.

listofcars::listofcars() {		//Constructor
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

void listofcars::addmiddlebyvalue(int a, float b, int value) {
    car *temp = new car;
    temp->year = a;
    temp->price = b;
    temp->next = nullptr;
    car* current = head;
    while (current->year != value) {
      current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

int main() {
  listofcars lexus;
  lexus.addatbeg(2010, 105.55);
  lexus.addatbeg(2022, 1367.55);
  lexus.addatend(2014, 989.003);
  lexus.addmiddlebyvalue(2023, 41666.90, 2022);
  lexus.print();
  return 0;
}