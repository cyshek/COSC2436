#include <iostream>

using namespace std;

//This is a program that prints all of the permutations of a string. Invokes itself recursively and backtracks to pass in the correct string argument.
void permute(string a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
        cout << a << endl; 
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 
  
int main() 
{ 
    string str = "ABC"; 
    int n = str.size(); 
    permute(str, 0, n-1); 
    return 0; 
} 