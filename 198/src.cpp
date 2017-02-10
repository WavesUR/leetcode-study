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
    int rob(vector<int>& nums) {
        int len = nums.size(); 
        if(nums.empty()){
          return 0;
        }
        vector<int> memo(len+1,0);
        memo[len - 1] = nums[len -1];
        for(int i = nums.size() - 2; i >= 0; i--){
          memo[i] = max(nums[i] + memo[i+2],memo[i+1]);
        }
        return memo[0];
    }
};

int main(){

  vector<int> nums = {1,2,3,4,5};
  Solution solution;
  int result = solution.rob(nums);

  cout << result << endl;


    
  return 0;
}