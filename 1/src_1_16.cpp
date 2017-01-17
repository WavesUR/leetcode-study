#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;

// Time complexity: O(n), traverse the list once.
// Space comlexity: O(n), depends on the position of answer, at most n elements


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> my_map;
        int len = nums.size();
        for(int i = 0; i < len; i++){
          auto t = my_map.find(target - nums[i]);
          if(t == my_map.end()){
            my_map[nums[i]] = i;
          }else{
            return {my_map[target-nums[i]],i};
          }

        }
        return {};
    }
};

int main(){


    vector<int> nums(5);
    nums = {-1,-2,-3,-4,-5};
    int target = -8;
    Solution solution;
    vector<int> result = solution.twoSum(nums,target);
    cout << result[0] << result[1] << endl;
    
  

    
	return 0;
}