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
    void dp(string p, int start, vector<int>& memo){
        if(start >= p.length() - 1){
          return;
        }
        if(memo[start] != -1){
          return;
        }else{
          dp(p,start+1,memo);
        }
        if(p[start]-p[start+1] == -1 || p[start]-p[start+1] == 'z'-'a'){
          memo[start] = memo[start+1] + 1;
        }else{
          memo[start] = 1;
        }
        return;

    }
    int findSubstringInWraproundString(string p) {
        if(p.length() == 0){
          return 0;
        }
        vector<int> memo(p.length(),-1);
        memo[p.length()-1] = 1;
        dp(p,0,memo);
        int sum = 0;
        for(int i = 0; i < p.length(); i++){
          sum = sum + memo[i];
        }
        return sum;
    }
};

int main(){

  string s = "azab";
  Solution solution;
  int result = solution.findSubstringInWraproundString(s);

  cout << result << endl;


    
  return 0;
}