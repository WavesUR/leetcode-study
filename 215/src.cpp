#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int left = 0;
       int right = nums.size() - 1;
       while(true){
         int cur = partition(nums, left, right);
         if(cur == k - 1){
          return nums[cur];
         }else if(cur > k - 1){
          right = cur - 1;
         }else{
          left = cur + 1;
         }        
       }

    }
    int partition(vector<int> & nums, int left, int right){
      int povit = nums[left];
      int i = left + 1;
      int j = right;
      while(i <= j){
        if(nums[i] < povit && nums[j] > povit){
          swap(nums[i],nums[j]);
          i++;
          j--;
        }
        if(nums[i] >= povit){
          i++;
        }
        if(nums[j] <= povit){
          j--;
        }
      }
      swap(nums[left],nums[j]);
      return j;
    }
};

int main(){

  vector<int> nums;
  nums = {3,2,1,5,6,4};
  int k = 2;
  Solution solution;
  int result = solution.findKthLargest(nums, k);

  cout << result << endl;


    
  return 0;
}