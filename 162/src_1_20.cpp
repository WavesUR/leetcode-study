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

//Time: O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
          return -1;
        }
        if(len == 1){
          return 0;
        }
        int l = 0, r = len - 1;
        if(nums[l] > nums[l+1]){
          return l;
        }
        l++;
        if(nums[r] > nums[r-1]){
          return r;
        }
        r--;
        while(l <= r){
          int c = l + (r - l) / 2;
          if(nums[c] > nums[c - 1] && nums[c] > nums[c+1]){
            return c;
          }else if(nums[c] < nums[c + 1]){
            l = c + 1 ;
          }else{
            r = c - 1 ;
          }
        }
        return -1;
    }
};

int main(){

  vector<int> nums;
  nums = {3,4,3,2,1};
  Solution solution;
  int result = solution.findPeakElement(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}