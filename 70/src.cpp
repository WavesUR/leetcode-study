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
    int dp(int n, vector<int>& memo){
        if(memo[n] != 0){
          return memo[n];
        }
        if(n == 1){
          return memo[n] =1;
        }
        if(n == 2){
          return memo[n] = 2;
        }
        return memo[n] = dp(n-2,memo) + dp(n-1,memo);

    }
    int climbStairs(int n) {
      vector<int> memo(n+1,0);
      return dp(n,memo);
  }  
};


int main(){

  vector<int> nums;
  nums = {1};
  Solution solution;
  int result = solution.climbStairs(4);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}