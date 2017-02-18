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
    bool canJump(vector<int>& nums) {
       int len = nums.size();
       int target = len - 1;
       int cur = len - 2; 
       while(cur >= 0){
        if(nums[cur] >= target - cur){
          target = cur;       
        }
          cur--;      
       }
       return target == 0 ? true : false;
    }
};
int main(){
  vector<int>  nums;
  nums = {0,1};
  Solution solution;

  bool result = solution.canJump(nums);
  cout << result << endl;


    
  return 0;
}