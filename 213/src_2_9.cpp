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
    int rob(vector<int>& nums) {
        if(nums.empty()){
          return 0;
        }
        int len = nums.size();
        vector<int> memo1(len+1,0);
        memo1[len - 1] = nums[len-1]; // rob last
        vector<int> memo2(len+1,0);
        memo2[len - 1] = 0; // not rob last one
        for(int i = len - 2; i >= 1; i--){
          memo1[i] = max(memo1[i+2]+nums[i],memo1[i+1]);
        }
        memo1[0] = max(memo1[1],memo1[0]);
        for(int i = len - 2; i >= 0; i--){
          memo2[i] = max(memo2[i+2]+nums[i],memo2[i+1]);
        }
        return max(memo1[0],memo2[0]);
    }
};


int main(){

  vector<int> nums;
  nums = {1};
  Solution solution;
  int result = solution.rob(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}