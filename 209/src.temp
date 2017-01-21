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
    int minSubArrayLen(int s, vector<int>& nums) {
        // if(nums.empty()){
        //   return 0;
        // }
        int len = nums.size();

        int sum = 0;
        int minlen = INT_MAX;
        int index = 0;

        for(int i = 0; i < len; i++){
          sum += nums[i];
          while(sum>=s){
            minlen = min(minlen, i-index+1);
            sum -= nums[index];
            index++;
          }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

int main(){

  vector<int> nums;
//  nums = {2,3,4,0,1};
  int target = 7;
  Solution solution;
  int result = solution.minSubArrayLen(target,nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}