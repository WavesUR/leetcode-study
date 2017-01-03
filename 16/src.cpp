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
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int min_diff = INT_MAX;
        for(int i = 0; i < len - 2; i++){
          int left = i + 1;
          int right = len - 1;
          while(left < right){
            int diff = nums[i] + nums[left] + nums[right] - target;
            if(abs(diff) < abs(min_diff)){
              min_diff = diff;
            }
            if(diff == 0){
              break;
            }else if(diff < 0){
              left++;
            }else{
              right--;
            }
          }
        }
        return min_diff+target;
    }
};


int main(){
  vector<int>  nums;
  nums = {-1, 2, 1, -4};
  int target = 1;
  Solution solution;

  int result = solution.threeSumClosest(nums, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << " ";
  // }
  // cout << endl;
  // cout << result << endl;
  cout << result << endl;


    
  return 0;
}