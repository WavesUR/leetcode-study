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

        int l = 0, r = nums.size() - 1, c;
        // if(nums[l]<=nums[r]){
        //   while(l<=r){
        //     c = l + (r - l) / 2;
        //     if(target == nums[c]){
        //       return c;
        //     }
        //     else if(target > nums[c]){
        //       l = c + 1;
        //     }else{
        //       r = c - 1;
        //     }
        //   }
        //   return -1;
        // }

        while(r > l){
          c = l + (r - l) /2;
          
          if(nums[c] == target){
            return c;
          }
          if(target > nums[r]){
            if(nums[c] >= nums[l] && nums[c] < target){
              l = c + 1;
            }else{
              r = c - 1;
            }           
          }
          if(target < nums[l]){
            if(nums[c] > target && nums[r] >= nums[c]){
              r = c - 1;
            }
            l = c + 1;
          }
        }
        return -1;
    }
};

int main(){

  vector<int> nums(5);
  nums = {2,3,4,0,1};
  int target = 1;
  Solution solution;
  int result = solution.search(nums, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}