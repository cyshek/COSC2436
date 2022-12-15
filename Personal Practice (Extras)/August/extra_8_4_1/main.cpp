#include <iostream>
#include "ArgumentManager.h"
using namespace std;

//This program computes the number of arguments passed into main. Used to determine specific arguments as well.

int main (int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        
        cout << argv[i] << endl;
    }

    cout << "Number of arguments: " << argc;

} 
/*int main () {
  cout << "Hello" << endl;
  cout << "world" << endl;
  return 0;
}
*/
