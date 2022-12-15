#include <iostream>
using namespace std;


//Creates three student objects and prints their age and gpa. We access the next element by setting a temporary pointer to each Student.
struct Student {
int age;
float gpa;
Student* next; //Holds the address of the next Student. Points to next student
};
int main() {
  //Static allocation
  Student Eric;
  Eric.age = 19;
  Eric.gpa = 4.022;
  Eric.next = 0;
  
  //Dynamic allocation
  Student *p = new Student;
  //Student *head = p; //Save first element
  
  p->age = 20;
  p->gpa = 3.456;
  //p->next = nullptr;
  p->next = new Student;
  cout << "Age: " << p-> age <<" GPA: " << p->gpa << endl;
  p = p->next;
  p->age = 25;
  p->gpa = 2.567;
  p->next = new Student;
  cout << "Age: " << p-> age <<" GPA: " << p->gpa << endl;
  p = p->next;
  p->age = 30;
  p->gpa = 3.987;
  p->next = nullptr;
  cout << "Age: " << p-> age <<" GPA: " << p->gpa << endl;
  //Dynamic array students
  Student *arr = new Student[3]; //Arr is a pointer to three memory cells, each consisting of "age" and "gpa"
  arr->age = 21;
  arr->gpa = 3.0;
  arr++;

  arr->age = 22;
  arr->gpa = 3.1;
  arr++;
  return 0;
}