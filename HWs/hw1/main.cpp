#include "ArgumentManager.h"
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
    string command = am.get("command");
    string input = am.get("input");
    string output = am.get("output");

  //Change back to input and output and command
    ifstream inputFile(input);
    ifstream commandFile(command);
    ofstream outputFile(output);

    //Stores all of the input strings.
    vector<string> tests;
    string t;
  
    while(getline(inputFile, t)) {
      t.erase(remove(t.begin(), t.end(), ' '), t.end());
      t.erase(remove(t.begin(), t.end(), '\n'), t.end());
      t.erase(remove(t.begin(), t.end(), '\r'), t.end());
      tests.push_back(t);
      //cout << t << endl;
    }

    string id;
    char character;
    string number;
    string temp;
    bool beforeColon = true;
    bool beforeSemi = false;
    bool isValid = false;
    vector<string> fixedCodes;
    string replaceHash;
    string decoded;

    //Holds the characters and their respective values
    unordered_map<char, string> codes;

    //Iterates through each string and separates the character, number, and id.
    for (int i = 0; i < tests.size(); i++) {
      for (int j = 0; j < tests.at(i).size(); j++) {
        if (tests.at(i).find(";id") == string::npos){
          break;
        }
        if (tests[i][j] == ':') {
          beforeColon = false; 
          beforeSemi = true;
          continue;
        }
        if (tests[i][j] == ';') {
          codes[character] = number;
          number = "";
          if (tests[i].substr(j, 4) == ";id:") {
            id = tests[i].substr(j + 4);
            beforeSemi = false;
            beforeColon = true;
            break;
          }
          beforeSemi = false;
          beforeColon = true;
          continue;
        }
        if (beforeColon) {
          character = tests[i][j];
        }
        if (beforeSemi) {
          number += tests[i][j];
        }
      }
      
      //Decoding process begins here.
      for (int z = 0; z < id.length(); z++) {
        if (codes.find(id.at(z)) != codes.end()) {
          replaceHash += codes[id.at(z)];
        } else if (id.at(z) == '#') {
          replaceHash += '#';
        } else {
          replaceHash += id.at(z);
        }
      }

      //Replace '#' with its index
      for (int i = 0; i < replaceHash.length(); i++) {
        if (replaceHash.at(i) == '#') {
          decoded += to_string(i);
        } else {
          decoded += replaceHash.at(i);
        }
      }
      
      fixedCodes.push_back(decoded);
      replaceHash = "";
      decoded = "";
      id = "";
      codes.clear();
    }

    //Filter output based on command file input.
    string inputCommands [101];
    vector<string> firstFour;
    vector<string> lastFour;
    int a = 0;

    //Extracts commands from file.
    string temp2;
    while(getline(commandFile, temp2)) {
      temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
      temp2.erase(remove(temp2.begin(), temp2.end(), '\n'), temp2.end());
      temp2.erase(remove(temp2.begin(), temp2.end(), '\r'), temp2.end());
      inputCommands[a] = temp2;
      a++;
    }

    //If command file is empty, output valid decodes.
    if (a == 0) {
      //cout << fixedCodes.size() << endl;
      for (int i = 0; i < fixedCodes.size(); i++) {
        if (i == (fixedCodes.size() - 1)) {
          outputFile << fixedCodes[i];
          inputFile.close();
          commandFile.close();
          outputFile.close();
          exit(-1);
        } else {
          outputFile << fixedCodes[i] << "\n";
        }  
      }
    }

    //Add the correct commands to their respective vectors.
    for (int b = 0; b < a; b++) {
      if (inputCommands[b][0] == 'f') {
        firstFour.push_back(inputCommands[b].substr(7));
      } else if (inputCommands[b][0] == 'l') {
        lastFour.push_back(inputCommands[b].substr(6));
      }
    } 

    /*for (auto x: fixedCodes) {
      cout << x << endl;
    }*/
    
    bool onlyFirst = false;
    bool onlyLast = false;
  
    if (firstFour.size() > 0 && lastFour.size() <= 0) {
      onlyFirst = true;
    } else if (lastFour.size() > 0 && firstFour.size() <= 0) {
      onlyLast = true;
    } 

   //Filter output based on commands given.
   for (int i = 0; i < fixedCodes.size(); i++) {
      if (onlyFirst) {
        for (int j = 0; j < firstFour.size(); j++) {
          if (fixedCodes[i].substr(0, 4) == firstFour[j]) {
            outputFile << fixedCodes[i] << "\n";
          }
        } 
      } else if (onlyLast) {
         for (int k = 0; k < lastFour.size(); k++) {
          if (fixedCodes[i].substr(0, 4) == lastFour[k]) {
            outputFile << fixedCodes[i] << "\n";
          }
        }       
      } else {
        for (int l = 0; l < firstFour.size(); l++) {
          if (fixedCodes[i].substr(0, 4) == firstFour[l]) {
            for (int m = 0; m < lastFour.size(); m++) {
              if (fixedCodes[i].substr(fixedCodes[i].size() - 4) == lastFour[m]) {
                outputFile << fixedCodes[i] << "\n";
                break;
              }
            }
            break;
          }
        }        
      }
    }
    
    inputFile.close();
    commandFile.close();
    outputFile.close();

}