#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1){
          return false;
        }
        unordered_map<int,int> my_map;
        for(int i = 0; i < nums.size(); i++){
          if(my_map.find(nums[i]) == my_map.end() && i - my_map[nums[i]] <= k){           
                return true;
              }
              my_map[nums[i]] = i;           
          }
        
        return false;
    }
};


int main(){


    vector<int>  nums(4);
    nums = {-1,2,3,-1};
    int k = 1;
    Solution solution;
    bool result = solution.containsNearbyDuplicate(nums,k);
    cout << result << endl;
    
  

    
	return 0;
}