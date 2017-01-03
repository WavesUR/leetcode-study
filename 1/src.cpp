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


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size()<2){
          return v;
        }

        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); i++){
          int key = mymap[target - nums[i]];
          if(key != 0){
            return {key - 1, i};
          }
          mymap[nums[i]] = i + 1;
         }
        return v;
    }
};

int main(){


    vector<int> nums(4);
    nums = {2,9,11,15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums,target);
 //   cout << result[0] << result[1] << endl;
    
  

    
	return 0;
}