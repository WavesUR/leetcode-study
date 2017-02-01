#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// first vaild one (mid > target)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid; // right may change
        while(left < right){ // may change
          mid = left + ((right - left) >> 1); // may change
          if(nums[mid] == target){
            return mid;
          }else if(nums[mid] < target){
            left = mid + 1;
          }else{
            right = mid;
          }
        }
        return nums[right] >= target ? right : right+1; 
    }
};

int main(){

  int target = 1;
  int result;
  vector<int> nums = {1}; 
  Solution solution;
  result = solution.searchInsert(nums,target);

for (int i = 0; i < nums.size(); ++i)
{
  cout << nums[i] << " ";
}
cout << endl;
  cout << result << endl;

  return 0;
}