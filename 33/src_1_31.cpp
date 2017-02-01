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

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         if(nums.empty()){
//           return -1;
//         }
//         int left = 0, right = nums.size() - 1, mid;
//         while(left <= right){
//           mid = left + (right - left) /2;
//           if(nums[mid] == target){
//             return mid;
//           }else if(nums[mid] >= nums[left]){
//             if(target == nums[left]){
//               return left;
//             }else if(target > nums[left] && target < nums[mid]){
//               right = mid - 1;
//             }else{
//               left = mid + 1;
//             }
//           }else if(nums[mid] <= nums[right]){
//             if(target == nums[right]){
//               return right;
//             }else if(target < nums[left] && target > nums[mid]){
//               left = mid + 1;
//             }else{
//               right = mid - 1;
//             }
//           }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
          return -1;
        }
        int left = 0, right = nums.size() - 1, mid;
        // first find pivot
        while(left < right){
          mid = left + (right - left) / 2;
          if(nums[mid] <= nums[right]){
            right = mid;
          }else{
            left = mid + 1;
          }
        }
        int pivot = right;
        // then treat it as normal sorted array
        left = 0, right = nums.size()-1;
        while(left <= right){
          mid = left + (right - left) /2;
          int mid_r = (mid + pivot)%nums.size();
          if(nums[mid_r] == target){
            return mid_r;
          }else if(nums[mid_r] > target){
            right = mid - 1;
          }else{
            left = mid + 1;
          }
        }
        return -1;
    }
};

int main(){

  vector<int> nums;
  nums = {7,9,1,3,5};
  int target = 1;
  Solution solution;
  int result = solution.search(nums, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}