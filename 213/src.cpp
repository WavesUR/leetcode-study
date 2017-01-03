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
    int rob(vector<int>& nums) {
  
        int len = nums.size();
        if(len < 2){
          return len ? nums[0] : 0;
        }
        
        return max(helper(nums,0,len-2),helper(nums,1,len-1));
    }
    int helper(vector<int>& nums, int start, int last){
        int result = 0;
        int pre_pre = 0;         
        int pre = 0;      
      for(int i = start; i <= last; i++){
        pre_pre = pre;
        pre = result;
        result = max(pre, pre_pre+nums[i]);
      }
      return result;
    }
};


int main(){

  vector<int> nums;
  nums = {1,1,1};
  Solution solution;
  int result = solution.rob(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}