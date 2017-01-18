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

// Time complexity: O(n), traverse the list once.
// Space comlexity: O(1)


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> max_num(3);
        max_num = {INT_MAX,INT_MAX,INT_MAX};
        for(int i = 0; i < nums.size(); i++){
          if(nums[i] == max_num[0] || nums[i] == max_num[1] || nums[i] == max_num[2]){
            continue;
          }
          else if(nums[i] > max_num[0] || max_num[0] == INT_MAX){
            max_num[2] = max_num[1];
            max_num[1] = max_num[0];
            max_num[0] = nums[i];
            
          }else if(nums[i] > max_num[1] || max_num[1] == INT_MAX){
            max_num[2] = max_num[1];
            max_num[1] = nums[i];
          }else if(nums[i] > max_num[2] || max_num[2] == INT_MAX){
            max_num[2] = nums[i];
          }
        }
        if(max_num[2] == INT_MAX){
          return max_num[0];
        }else{
          return max_num[2];
        }
        
    }
};

int main(){


    vector<int> nums(4);
    nums = {2,2,3,1};
    Solution solution;
    int result = solution.thirdMax(nums);
    cout << result << endl;
    
  

    
	return 0;
}