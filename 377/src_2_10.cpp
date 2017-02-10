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
    int dp(vector<int>& nums, int target, vector<int>& memo){
      if(memo[target] != -1){
        return memo[target];
      }
      int sum = 0;
      for(int i = 0; i < nums.size();i++){
        if(target >= nums[i]){
          sum = sum + dp(nums,target-nums[i], memo);
        }
      }
      memo[target] = sum;
      return sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
      if(target <= 0){
        return 0;        
      }
      vector<int> memo(target+1,-1);
      memo[0] = 1;
      return dp(nums,target,memo);
    }
};

int main(){

  vector<int> nums;
  nums = {1, 2, 3};
  int target = 4;
  Solution solution;
  int result = solution.combinationSum4(nums,target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}