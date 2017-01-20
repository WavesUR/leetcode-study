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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > v;
        int len = nums.size();
        if(len<3){
          return v;
        }
        sort(nums.begin(),nums.end());
        // {cur,left,right}
        for(int cur = 0; cur < len - 2 && nums[cur] <= 0; cur++){
          if(cur != 0 && (nums[cur] == nums[cur-1])){
            continue;
          }
          int left = cur + 1;
          int right = len - 1;

          while(left < right){
            int result = nums[cur] + nums[left] + nums[right];
            if(result == 0){
              v.push_back({nums[cur],nums[left],nums[right]});
              do{
                left++;
              }while(nums[left] == nums[left-1] && left + 1 < right);
              do{
                right--;
              }while(nums[right] == nums[right+1] && right - 1 > left);
            }else if(result < 0){
              do{
                left++;
              }while(nums[left] == nums[left-1] && left + 1 < right);
            }else{
              do{
                right--;
              }while(nums[right] == nums[right+1] && right - 1 > left);
            } 
          }
        }
       
        return v;
    }
};


int main(){
  vector<int> nums;
  nums = {0,0,0};
  Solution solution;

  vector<vector<int> > result = solution.threeSum(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[0].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
 // cout << result << endl;
  // cout << result << endl;


    
  return 0;
}