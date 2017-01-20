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

// Time: O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min_diff = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++){
          if(i > 0 && nums[i] == nums[i] - 1){
            continue;
          }
          int left = i + 1, right = nums.size() - 1;
          while(left < right){
            int diff = nums[i] + nums[left] + nums[right] - target;
            min_diff = (abs(diff) < abs(min_diff)) ? diff : min_diff;
            if(diff == 0){
                return target;
            }else if(diff > 0){
              right--;
            }else{
              left++;
            }
          }
        }
        return target + min_diff;
    }
};


int main(){
  vector<int>  nums;
  nums = {-1, 2, 1, -4};
  int target = 1;
  Solution solution;

  int result = solution.threeSumClosest(nums, target);
  cout << result << endl;


    
  return 0;
}