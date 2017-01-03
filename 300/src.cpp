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
    int lengthOfLIS(vector<int>& nums) {
      int len = nums.size();
      if(len <= 1){
        return len;
      }
      int result = 0;
      vector<int> mem(len);
      for(int i = 0; i < len; i++){
        mem[i] = 1;
        for(int j = 0; j< i ; j++){
          if(nums[j] < nums[i]){
            mem[i] = max(mem[i],mem[j]+1);
          }
        }
        result = max(result, mem[i]);
      }
      return result;
    } 
};


int main(){

  vector<int> nums;
  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  Solution solution;
  int result = solution.lengthOfLIS(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}