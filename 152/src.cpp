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
    int maxProduct(vector<int>& nums) {
        int max_p = INT_MIN;
//        int min_p = INT_MAX;
        int max_current = 1; // every time, multiply negtive value, the max and min flip
        int min_current = 1; // 
        for(int i = 0; i < nums.size(); i++){
          if(nums[i] < 0){
            swap(max_current,min_current);
          }
          max_current = max(max_current * nums[i],nums[i]);
          min_current = min(min_current * nums[i],nums[i]);
          max_p = max(max_current, max_p);
//          min_p = min(min_current, min_p);
        }
        return max_p;
    }
};

int main(){

  vector<int> nums;
  nums = {10,2,-3,4,10,-2};
  Solution solution;
  int result = solution.maxProduct(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}