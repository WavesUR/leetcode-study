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

//Time: O(n)!!!
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if(nums.size() == 0){
        return 0;
      }
        int sum = 0;
        int min_len = INT_MAX;
        int start = 0, end = 0;
        while(end < nums.size()){
          sum = sum + nums[end];          
          while(sum >= s){
            min_len = min(min_len, end - start + 1);
            sum = sum - nums[start];
            start++;
          }
          end++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main(){

  vector<int> nums;
  nums = {10,2,3};
  int target = 6;
  Solution solution;
  int result = solution.minSubArrayLen(target,nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}