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
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
          return -1;
        }
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right){
          mid = left + (right - left) /2;
          if(nums[mid] == target){
            return mid;
          }else if(nums[mid] >= nums[left]){
            if(target == nums[left]){
              return left;
            }else if(target > nums[left] && target < nums[mid]){
              right = mid - 1;
            }else{
              left = mid + 1;
            }
          }else if(nums[mid] <= nums[right]){
            if(target == nums[right]){
              return right;
            }else if(target < nums[left] && target > nums[mid]){
              left = mid + 1;
            }else{
              right = mid - 1;
            }
          }
        }
        return -1;
    }
};
int main(){

  vector<int> nums;
  nums = {1,3,5,7,9};
  int target = 1;
  Solution solution;
  int result = solution.search(nums, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}