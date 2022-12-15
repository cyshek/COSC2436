#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

map<string, int> mappy;
map<string, int>::iterator itty;

void addToMap (string str) {
  mappy[str]++;
}

void printMap(ostream& output) {
  for (itty = mappy.begin(); itty != mappy.end(); ++itty) {
    output << itty->first << ": " << itty->second << endl;
  }
}

void cleanUpString (string& line) {
  line.erase(remove(line.begin(), line.end(), '?'), line.end());
  line.erase(remove(line.begin(), line.end(), '"'), line.end());
  line.erase(remove(line.begin(), line.end(), '!'), line.end());
  line.erase(remove(line.begin(), line.end(), '.'), line.end());
  line.erase(remove(line.begin(), line.end(), ','), line.end());
  line.erase(remove(line.begin(), line.end(), '\n'), line.end());
  line.erase(remove(line.begin(), line.end(), '\r'), line.end());
  transform(line.begin(), line.end(), line.begin(), ::tolower);
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
    
  //ifstream input("input.txt");
  //ofstream output("output.txt");

  string line = "";
  string word = "";
  
  while(getline(input, line)) {
    cleanUpString(line);
    for (;;) {
      word = line.substr(0, line.find(" "));
      if (word != "") {
        addToMap(word);
      }
      line = line.substr(line.find(" ") + 1); 
      if (line.find(" ") == string::npos) {
        if (line != "") {
          addToMap(line);
        }
        break;
      }
    }
  }
  printMap(output);
}