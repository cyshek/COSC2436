#include <iostream>
#include <unordered_map>
using namespace std;

//This is a program that creates and fills an unordered map. The map contains keys representing the students, and each key's corresponding value which represents that student's grade.
int main() {
  unordered_map<string, int> gradebook;
  gradebook["Morgan"] = 99;
  gradebook["Billy"] = 90;
  gradebook["Joe"] = 100;
  gradebook["Cash"] = 34;

  cout << "Students and their grades" << endl;
  
  for (auto map : gradebook) {
    cout << map.first << "  " << map.second << endl;
    
  }

  return 0;
}