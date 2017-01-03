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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
          return;
        }
        int i = len - 1;
        while(nums[i] <= nums[i-1]){
          if(i == 1){
          int k = len - 1;
          int j = 0;
          while(j <= k){
          swap(nums[j],nums[k]);
          j++;
          k--;
        }
        return;
          }
          i--;
        }
        int target_index = i-1;
        int j = len - 1;
        while(nums[j] <= nums[target_index]){
          j--;
        }
        swap(nums[j],nums[target_index]);
        int k = len - 1;
        while(i <= k){
          swap(nums[i],nums[k]);
          i++;
          k--;
        }

    }
};

int main(){

  vector<int> nums;
  nums = {1,5,1};
  Solution solution;
  solution.nextPermutation(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << endl;
  }


    
  return 0;
}