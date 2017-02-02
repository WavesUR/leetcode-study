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
    bool increasingTriplet(vector<int>& nums) {
        int min_val = INT_MAX;
        int mid_val = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
          if(nums[i] <= min_val){
            min_val = nums[i];
          }else if(nums[i] <= mid_val){
            mid_val = nums[i];
          }else{
            return true;
          }
        }
        return false;
    }
};
int main(){

  vector<int> nums;
  nums = {1,2,3,1,2,1};
  Solution solution;
  bool result = solution.increasingTriplet(nums);
  cout << result << endl;


    
  return 0;
}