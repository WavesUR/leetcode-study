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