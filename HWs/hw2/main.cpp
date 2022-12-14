#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

//This is a program that adds credentials, each represented as a node, to a Credentials linked list. 

struct Node {
  string id;
  string username;
  string score;
  string grade;
  string cred;
  Node* next;
};

class Credentials {
private:
  Node* head;
  Node* tail;
  int nodeCount;
public:
  Credentials() {
    head = nullptr;
    tail = nullptr;
    nodeCount = 0;
  }
  void printList(ostream& output) {
    Node* cu = head;
    while (cu->next != nullptr) {
      output << cu->cred << "\n";
      cu = cu->next;
    }
    if (cu->next == nullptr) {
      output << cu->cred; 
    }
  }
  void insert(string i, string u, string s, string g, int index) {
    if (index > nodeCount) { return; }
    Node* temp = new Node;
    temp->id = i;
    temp->username = u;
    temp->score = s;
    temp->grade = g;
    temp->cred = "[id:" + i + ";username:" + u + ";score:" + s + ";grade:" + g +"]";
    Node* current = head;
      for (int num = 0; num < nodeCount; num++) {
        if (current->id == i) {
          current->username = u;
          current->score = s;
          current->grade = g;
          current->cred = "[id:" + i + ";username:" + u + ";score:" + s + ";grade:" + g +"]";
          return;
        } else if (current->username == u) {
          return;
        }
        current = current->next;
      }
      current = head;
      if (index == 0) {
        temp->next = head;
        head = temp;
        nodeCount++;
        return;
      } else if (index == nodeCount) {
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
        nodeCount++;
        return;
      }
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }
      temp->next = current->next;
      current->next = temp;
      nodeCount++;
  }
  void insertEnd(string i, string u, string s, string g) {
    if (head == nullptr) {
      head = new Node;
      head->id = i;
      head->username = u;
      head->score = s;
      head->grade = g;
      head->cred = "[id:" + i + ";username:" + u + ";score:" + s + ";grade:" + g +"]";
      head->next = nullptr;
      tail = head;
      nodeCount++;
    } else {
      Node* curr = head;
      while (curr != nullptr) {
        if (curr->id == i) {
          curr->username = u;
          curr->score = s;
          curr->grade = g;
          curr->cred = "[id:" + i + ";username:" + u + ";score:" + s + ";grade:" + g +"]";
          return;
        } else if (curr->username == u) {
          return;
        }
        curr = curr->next;
      }
      Node* temp = new Node;
      temp->next = nullptr;
      temp->id = i;
      temp->username = u;
      temp->score = s;
      temp->grade = g;
      temp->cred = "[id:" + i + ";username:" + u + ";score:" + s + ";grade:" + g +"]";
      tail->next = temp;
      tail = temp;
      nodeCount++;
    }
  }
  void deleteValue (string val) {
      Node* curr = head;
      Node* temp;
      Node* prev = nullptr;
      while (curr != nullptr) {
        if (curr->cred.find(val) != string::npos) {
          if (curr == head) {
            temp = curr;
            curr = curr->next;
            head = curr;
            delete temp;
            nodeCount--;
          } else if (curr == tail) {
            prev->next = nullptr;
            tail = prev;
            delete curr;
            nodeCount--;
            return;
          } else {
            prev->next = curr->next;
            temp = curr;
            curr = curr->next;
            delete temp;
            nodeCount--;
          }
        } else {
          prev = curr;
          curr = curr->next;
        }
      }
    }

  void swap(Node* cu, Node* prev);
  void sort(int);
  int getListSize() { return nodeCount; }
};

void Credentials::swap(Node* cu, Node* prev) {
        Node* temp = new Node;
        temp->id = prev->id;
        temp->username = prev->username;
        temp->score = prev->score;
        temp->grade = prev->grade;
        temp->cred = prev->cred;
        prev->id = cu->id;
        prev->username = cu->username;
        prev->score = cu->score;
        prev->grade = cu->grade;
        prev->cred = cu->cred;
        cu->id = temp->id;
        cu->username = temp->username;
        cu->score = temp->score;
        cu->grade = temp->grade;
        cu->cred = temp->cred;
}

void Credentials::sort(int code) {
    Node* cu = head;
    Node* prev = nullptr;
    bool unsorted = true;
    if (head == nullptr || head->next == nullptr)
        return;
    while (unsorted) { 
        unsorted = false; 
        cu = head;
        while(cu->next != nullptr) { 
          prev = cu;
          cu = cu->next;
          if (code == 1) {
            if(prev->grade > cu->grade){                    
              swap(cu, prev);
              unsorted = true;
            }            
          } else if (code == 2) {
            if(prev->username > cu->username){                    
              swap(cu, prev);
              unsorted = true;
            }            
          } else if (code == 3) {
            if(stoi(prev->score) < stoi(cu->score)) {                    
              swap(cu, prev);
              unsorted = true;
            }             
          } else if (code == 4) {
            if(stoi(prev->id) > stoi(cu->id)) {              
              swap(cu, prev);
              unsorted = true;
            }           
          }
        }
      }
  }

void processCreds (string currCred, Credentials& credList, bool com, int index) {
  int semiPos, semi2Pos;
  string id, username, score, grade;
  if (currCred.substr(1, 2) == "id") {
    id = currCred.substr(4, 4);
  } else {
    return;
  }
  if (currCred.substr(9, 8) == "username") {
    username = currCred.substr(18);
    semiPos = username.find(';');   
    username = username.substr(0, semiPos);    
  } else {
    return;
  }
  if (currCred.substr(18).substr(semiPos + 1, 5) == "score") {
    score = currCred.substr(18).substr(semiPos + 7);
    semi2Pos = score.find(';'); 
    score = score.substr(0, semi2Pos);
  } else {
    return;
  }
  if (currCred.substr(18).substr(semiPos + 7).substr(semi2Pos + 1, 5) == "grade") {
    grade = currCred.substr(18).substr(semiPos + 7).at(semi2Pos + 7);
  } else {
    return;
  }
  if (com) {
    if (index == -1) {
      credList.insertEnd(id, username, score, grade);
    } else {
      credList.insert(id, username, score, grade, index);
    }
  } else {
    credList.insertEnd(id, username, score, grade);
  }   
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ifstream command(am.get("command"));
  ofstream output(am.get("output"));

  //ifstream input("input1.txt");
  //ifstream command("command1.txt");
  //ofstream output("output1.txt");

  string in = "";
  vector<string> inputCredentials;
  vector<string> inputCommands;
  
  while(getline(input, in)) {
    in.erase(remove(in.begin(), in.end(), '\n'), in.end());
    in.erase(remove(in.begin(), in.end(), '\r'), in.end());
    inputCredentials.push_back(in);
    in = "";
  }

  while(getline(command, in)) {
    in.erase(remove(in.begin(), in.end(), '\n'), in.end());
    in.erase(remove(in.begin(), in.end(), '\r'), in.end());
    inputCommands.push_back(in);
    in = "";
  }
    
  Credentials credList;
  string curr, currCmd, value;
  int endOfPar, index;
  
  for (int i = 0; i < inputCredentials.size(); i++) {
    curr = inputCredentials.at(i);
    processCreds(curr, credList, false, -1);
  }

  for (int i = 0; i < inputCommands.size(); i++) {
    currCmd = inputCommands.at(i);
    if (currCmd.substr(0, 3) == "Add") {
      endOfPar = currCmd.find(')');
      index = stoi(currCmd.substr(5, endOfPar - 5));
      if (index > credList.getListSize() || index < 0) {
        continue;
      } else if (index == credList.getListSize()) {
        processCreds(currCmd.substr(currCmd.find('[')), credList, true, -1);
      } else {
        processCreds(currCmd.substr(currCmd.find('[')), credList, true, index);
      }
    } else if (currCmd.substr(0, 6) == "Remove") {
      credList.deleteValue(currCmd.substr(8, currCmd.size() - 9));
    } else if (currCmd.substr(0, 4) == "Sort") {
      value = currCmd.substr(6, currCmd.find(')') - 6);
      if (value == "grade") {
        credList.sort(1);
      } else if (value == "username") {
        credList.sort(2);
      } else if (value == "score") {
        credList.sort(3);
      } else if (value == "id") {
        credList.sort(4);
      }
    }
  }

  credList.printList(output);

  input.close();
  command.close();
  output.close();
}
