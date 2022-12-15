#include <iostream>
using namespace std;

//This program allows a user to see the difference between dynamic and static allocation of memory for a variable. Also shows how to dynamically create a Student. 

struct Student {
  string name;
  int id;
};
int main() {

  //static allocation of a
  int a = 10;
  cout << "slooowww " << a << endl;

  //dynamic allocation of b
  int *p = &a;
  cout << "fast " << *p << endl;
  cout << "memory address " << p << endl;
  p = nullptr;

  p = new int;
  *p = 10;
  cout << *p << endl;
  delete p;
  p = nullptr;

  Student *person = new Student;
  person->id = 123;
  person->name = "Billy";

  cout << person->id << endl;
  return 0;
}