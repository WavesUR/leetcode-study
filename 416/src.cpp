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
#include <utility>
using namespace std;

//DFS, slow
// class Solution {
// public:
//     bool dfs(vector<int>& nums, int start, int sum){
//       if(sum < 0){
//         return false;
//       }
//       if(nums[start] == sum){
//         return true;
//       }
//       for(int i = start+1; i < nums.size(); i++){
//         if(dfs(nums,i,sum-nums[start])){
//           return true;
//         }
//       }
//       return false;
//     }
//     bool canPartition(vector<int>& nums) {
//         if(nums.size() <=1){
//           return false;
//         }
//         int sum = 0;
//         for(int i = 0; i < nums.size();i++){
//           sum = sum + nums[i];
//         }
//         if(sum%2==1){
//           return false;
//         }
//         sort(nums.begin(),nums.end());
//         return dfs(nums,0,sum/2);

//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() <=1){
          return false;
        }
        int sum = 0;
        for(int i = 0; i < nums.size();i++){
          sum = sum + nums[i];
        }
        if(sum%2==1){
          return false;
        } 
        int half = sum >> 1;
        vector<bool> memo(half+1,false);
        memo[half] = true;
        for(int i = 0; i < nums.size();i++){
          for(int j = nums[i]; j <= half;j++){
            if(memo[j]){
              memo[j-nums[i]] = true;
            }
          }
        } 
        return memo[0];      
    }
};

int main(){

  vector<int> nums = {1, 5,5,11};
  Solution solution;
  bool result = solution.canPartition(nums);

  cout << result << endl;


    
  return 0;
}