#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool * arr;
    int * fac;
    string getPermutation(int n, int k) {
        string s;
        arr = new bool[n]();
        fac = new int[n+1]();
        helper(s, k, n,n);
        return s;

    }
    int factorial(int n)
    {
      if(fac[n] != 0){
        return fac[n];
      }
      return fac[n] = (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    void helper(string& s, int k, int n, int range){
      if(s.length() == range){
        return;
      }
      int d = (k-1)/factorial(n-1);
      int temp = 0;
      for(int i = 0; i < range; i++){ 
        if(temp == d && arr[i] == false){
          cout << 888<<endl;
          s = s + char(i+1+'0');
          arr[i] = true;
          helper(s, (k-1)%factorial(n-1)+1, n-1, range);
          break;
        } 
        if(arr[i] == false){       
          temp++;
        }
      }        
    }
};

int main(){

  int n = 3;
  int k = 6;
  Solution solution;
  string result = solution.getPermutation(n, k);
  // for(int i = 0; i< result.size();i++){
  //   for(int j = 0; j < result[i].size();j++){
  //     cout << result[i][j] << " ";
  //   }  
  //   cout << endl;
  // }
  cout << result << endl;


    
  return 0;
}