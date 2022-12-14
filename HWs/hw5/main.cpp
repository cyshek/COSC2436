#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include "ArgumentManager.h"
using namespace std;

struct node {
    int *key;
    node **child;
    bool leaf;
    int n;
    node(int deg)
    {
        key = new int[deg];
        leaf = true;
        child=new node*[deg+1];
        n = 0;
        for(int i=0;i<deg;i++){
            child[i]=NULL;
        }
    }
    
    void print(int level,ofstream &fout, node*temp){
      if(level == 1){
        for(int i=0;i<n;i++){
          fout<<key[i]<<" ";
        }
      } else if(level>1 && leaf){
        return;
      } else {
        for(int i=0;i<=n;i++){
          child[i]->print(level - 1,fout, temp);
        }
      }
    }
    void height(int h, int& result, node*temp){
      if(!leaf){
        child[0]->height(h + 1, result, temp);
      } else {
        result=h;
      }  
    }
    void split(node*fullNode, int t){
      node*rightNode = new node(t);
      int i_right = 0, move_up = (t-1)/2;
      int n_fullNode = fullNode->n;
      int carry = fullNode->key[move_up],i_child=0;
      float val1 = ceil(float(t) / 2);
      int walk_child = val1;
      for(int i = move_up + 1; i < n_fullNode; i++){
        rightNode->key[i_right] = fullNode->key[i];
        i_right++;
        rightNode->n++;
        fullNode->n--;  
      }
      if(!fullNode->leaf){
        for(int a = walk_child; a <= t; a++){
          rightNode->child[i_child] = fullNode->child[a];
          i_child++;
        }
        rightNode->leaf=fullNode->leaf;
      }
      int hold = t - 1;
      while(child[hold] != fullNode){
        child[hold+1] = child[hold];
        hold = hold - 1;
      }
      int j = t - 1;
      child[hold+1] = rightNode;
      while(j != 0 && !key[j-1]){
        j = j - 1;
      }
      while(j != 0 && key[j-1] > carry){
        key[j] = key[j-1];
        j -= 1;
      }
      key[j] = carry;
      n++;
      fullNode->n--;
    }
    node* findNode(int data, node* node_active,int t,node*temp) {
      if(!leaf){
        int i=0;
        while(i<n && data>key[i] ){
          i++;
        }
        child[i]->findNode(data,this,t,temp);
      } else{
        int i = t;
        while(!key[i-1]){
          i--;
        }
        while(key[i-1]>data && i!=0){
          key[i]=key[i-1];
          i--;
        }
        n++;
        key[i]=data; 
      }
      if(n == t){
        if(this != temp){
          node_active->split(this,t);
        } else{
          node* s = new node(t);
          s->leaf=false;
          s->child[0]=this;
          s->split(this,t);
          return s;
        }
      }
      return temp;
    }
};

class btree{
  private:
    node* root;
    int t;
  public:
    btree(int val) : root(nullptr), t(val) {}
    
    node* getRoot(){ return root; }

    int height(){
        int result;
        root->height(1,result, root);
        return result;
    }
    
    void print(int level,ofstream &fout){
        root->print(level,fout, root);
    }

    void insert(int data){
        if(root){
          root= root->findNode(data, root,t,root);
        }
        else{
          root=new node(t);
          root->leaf=true;
          root->key[0]=data;
          root->n=1;
        }
    }
};


int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ifstream command(am.get("command"));
  ofstream output(am.get("output"));
  
  //ifstream input("input3.txt");
  //ifstream command("command3.txt");
  //ofstream output("output1.txt");
  
  vector<int> levels;
  string str;
  int temp, degree, level, begin;

  while(getline(command, str)) {    
    if (str.find("=") != string::npos) {
      begin = str.find("=") + 1;
      degree = stoi(str.substr(begin, str.length() - begin));
    } else if (str.find("Level") != string::npos) {
      level = stoi(str.substr(6, str.length() - 6));
      levels.push_back(level);
    }
  }

  btree tree (degree);
  unordered_map<int, int> uniqueNums;
  
  while(input >> temp) {
    if (uniqueNums.find(temp) == uniqueNums.end()) {
      tree.insert(temp);
      uniqueNums[temp] = 1;
    }
  }
  
  int height = tree.height();
  output << "Height=" << height << "\n";
  
  for (int i: levels) {
    if (i > height) {
      output << "Empty" << "\n";
    } else {
      tree.print(i, output);
      output << "\n";
    }
  }
}