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

//Time: O(n)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if(nums.empty()){
//           return 0;
//         }
//         int sum = 0;
//         int max_sum = INT_MIN;
//         for(int i = 0; i < nums.size(); i++){
//           sum = sum + nums[i];
//           if(sum > max_sum){
//             max_sum = sum;
//           }
//           if(sum < 0){
//             sum = 0;
//           }
//         }
//         return max_sum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
          return 0;
        }
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
          sum = sum + nums[i];
          if(sum > max_sum){
            max_sum = sum;
          }
          if(sum < 0){
            sum = 0;
          }
        }
        return max_sum;
    }
};

int main(){
  vector<int> nums;
  nums = {-2,1,-3,4,-1,2,1,-5,4};
  Solution solution;

  int result = solution.maxSubArray(nums);
  cout << result << endl;
  // cout << result << endl;


    
  return 0;
}