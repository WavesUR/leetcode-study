#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int newindex(int index, int n){
      return (1 + 2 * index) % (n | 1);
    }
    void wiggleSort(vector<int>& nums) {
      int n = nums.size();
      auto minptr = nums.begin() + n /2; // find median
      nth_element(nums.begin(),minptr,nums.end());
      int mid = *minptr;
      int left = 0, right = n- 1;
      int i = 0;
      while(i <= right){
        if(nums[newindex(i,n)] > mid){
          swap(nums[newindex(left,n)],nums[newindex(i,n)]);
          left++;
          i++;
        }else if(nums[newindex(i,n)] < mid){
          swap(nums[newindex(right,n)],nums[newindex(i,n)]);
          right--;
        }else{
          i++;
        }
      }
    }
};



int main(){

  vector<int> nums = {1,2,3,4,5,6};
  Solution solution;
  solution.wiggleSort(nums);
  for(auto num:nums){
    cout << num << endl;
  }


    
  return 0;
}