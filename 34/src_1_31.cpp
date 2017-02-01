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
    vector<int> searchRange(vector<int>& nums, int target) {
      if(nums.empty()){
        return {-1, -1};
      }
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){
          mid = left + (right - left) /2 + 1;
          if(nums[mid] <= target){
            left = mid;
          }else{
            right = mid - 1;
          }
        }

        if(nums[left] != target){
          return {-1,-1};
        }
        int r2 = left;
        left = 0;
        right = r2;
        while(left < right){
          mid = left + (right - left) /2;
          if(nums[mid] >= target){
            right = mid;
          }else{
            left = mid + 1;
          }
        }
        return {right, r2};

    }
};

int main(){

  vector<int> nums = {5, 7, 7, 8, 8, 10};
  Solution solution;
  int target  = 9;
  vector<int> result = solution.searchRange(nums,target);
  cout << result[0] << result[1] << endl;


    
  return 0;
}