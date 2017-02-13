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

class Solution {
public:
    bool dfs(vector<int>& nums, int cur, int sum, vector<int>& cur_sum){
      if(cur == nums.size()){
        if(cur_sum[0] == sum && cur_sum[1] == sum && cur_sum[2] == sum){
          return true;
        }
        return false;
      }

        for(int i = 0; i < 4; i++){
          if(cur_sum[i] + nums[cur] > sum){
            continue;
          }
          cur_sum[i] += nums[cur];
          if(dfs(nums,cur+1,sum,cur_sum)){
            return true;
          }
          cur_sum[i] -= nums[cur];
        }
        return false;

      }
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if(len < 4){
          return false;
        }
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum = sum + nums[i];
        }
        if(sum%4 != 0){
          return false;
        }
        int edge = sum / 4;
        vector<int> cur_sum(4,0);
        sort(nums.rbegin(),nums.rend());
        return dfs(nums,0,edge,cur_sum);
        
    }
};

int main(){

  vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  Solution solution;
  bool result = solution.makesquare(nums);

  cout << result << endl;


    
  return 0;
}