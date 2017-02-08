#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    int dp(int n,vector<int>& memo){
       if(n == 0){
        memo[n] = 1;
        return 1;
       }
       if(n == 1){
        memo[n] = 1;
        return 1;
       }
       int sum = 0;
       for(int i = 1; i <= n;i++){
        if(memo[i-1] == 0){
          memo[i-1] = dp(i-1,memo);
        }
        if(memo[n-i] == 0){
          memo[n-i] = dp(n-i,memo);
        }
        sum = sum + memo[i-1]*memo[n-i];
       } 
       return memo[n] = sum;      
    }
    int numTrees(int n) {
        vector<int> memo(n+1,0);
        return dp(n,memo);
    }
};

int main(){

  int n = 4;
  Solution solution;
  int result = solution.numTrees(n);

  cout << result << endl;


    
  return 0;
}