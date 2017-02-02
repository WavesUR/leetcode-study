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

// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
          return len;
        }
        int max_len = 0;
        vector<int> memo(len,1);
        for(int i = len - 2; i >= 0 ; i--){
          for(int j = i + 1; j < len; j++){
            if(nums[i] < nums[j]){
              memo[i] = max(memo[i],memo[j]+1);
            }
          }
          max_len = max(max_len,memo[i]);
        }
        return max_len;
    }
};



int main(){
  vector<int> nums;
  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  Solution solution;
  int result = solution.lengthOfLIS(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}