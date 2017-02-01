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
        return {-1,-1};
      }
      
      int len = nums.size();
      int lower_b = lower(nums, 0, len-1, target); 
       if(nums[lower_b] != target){
        return {-1,-1};
      }  
         
      int upper_b = upper(nums, lower_b, len-1, target);

      return {lower_b,upper_b};

    }

    int lower(vector<int>& nums, int l, int r, int target){
      while(l != r){
        int c = l + (r-l)/2;
        if(nums[c] < target){
          l = c + 1;
        }else{
          r = c;
        }
      }
      return l;
    }
    int upper(vector<int>& nums, int l, int r, int target){
      while(l != r){
        int c = l + (r-l)/2 + 1;
        if(nums[c] > target){
          r = c - 1;
        }else{
          l = c;
        }
      }
      return l;
    }
};

int main(){

  vector<int> nums(2);
  nums = {1,3};
  Solution solution;
  int target  =1;
  vector<int> result = solution.searchRange(nums,target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << " ";
  // }
  // cout << endl;
  // cout << result << endl;
  cout << result[0] << result[1] << endl;


    
  return 0;
}