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
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int max_p = INT_MIN;
// //        int min_p = INT_MAX;
//         int max_current = 1; // every time, multiply negtive value, the max and min flip
//         int min_current = 1; // 
//         for(int i = 0; i < nums.size(); i++){
//           if(nums[i] < 0){
//             swap(max_current,min_current);
//           }
//           max_current = max(max_current * nums[i],nums[i]);
//           min_current = min(min_current * nums[i],nums[i]);
//           max_p = max(max_current, max_p);
// //          min_p = min(min_current, min_p);
//         }
//         return max_p;
//     }
// };

//dp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int> > memo(len+1,make_pair(1,1)); // maximum minimum
        int max_val = INT_MIN;
        for(int i = len - 1; i >= 0; i--){
          if(nums[i] >= 0){
              memo[i].first = max(nums[i], nums[i] * memo[i+1].first);
              memo[i].second = min(nums[i], nums[i] * memo[i+1].second);
              max_val = max(max_val,memo[i].first);
          }else{
              memo[i].first = max(nums[i], nums[i] * memo[i+1].second);
              memo[i].second = min(nums[i], nums[i] * memo[i+1].first);  
              max_val = max(max_val,memo[i].first);         
          }
        }
        return max_val;
    }
};

int main(){

  vector<int> nums;
  nums = {0,2};
  Solution solution;
  int result = solution.maxProduct(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}