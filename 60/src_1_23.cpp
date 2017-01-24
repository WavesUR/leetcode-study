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
    void factorial(int n, vector<int>& fac){
      fac[0] = 1;
      for(int i = 1; i <= n;i++){
        fac[i] = fac[i-1] * i;
      }
    }
    void backtrack(int n, int k, int cur, vector<int>& fac, string& s, vector<int>& memo){
        if(cur == n){
          return;
        }

        int c = (k-1)/fac[n-cur-1];
        int count = 0;
        for(int i = 1; i <= n; i++){
          if(memo[i-1] == 1){
            continue;
          }

          if(count < c){
            count++;
          }else{
            memo[i-1] = 1;
            s = s + to_string(i);
            backtrack(n,(k-1)%fac[n-cur-1]+1,cur+1,fac,s,memo);
            break;
          }

        }
    }
    string getPermutation(int n, int k) {
        vector<int> fac;
        fac = vector<int>(n+1,0);
        factorial(n, fac);
        string s;
        vector<int> memo;
        memo = vector<int>(n,0);
        int cur = 0;
        backtrack(n,k,cur,fac,s,memo);
        return s;
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