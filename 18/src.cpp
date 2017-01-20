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

// Time: O(n^3)
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > v;
        int n = nums.size();        
        if(n < 4){
          return v;
        }

        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 3; i++){
          if(i > 0 && nums[i] == nums[i - 1]){
            continue;
          }
          if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
          if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
          for(int j = i + 1; j < n - 2; j++){
            if(j > i + 1 && nums[j] == nums[j - 1]){
              continue;
            }
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
            if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
            int left = j + 1, right = n - 1;

            while(left < right){
              int sum = nums[i] + nums [j] + nums[left] + nums[right];
              if(sum == target){
                  v.push_back({nums[i],nums [j],nums[left],nums[right]});
                  do{
                    left++;
                  }while(nums[left] == nums[left-1] && left + 1 < right);
                  do{
                    right--;
                  }while(nums[right] == nums[right + 1] && right > left + 1);
              }else if(sum > target){
                  do{
                    right--;
                  }while(nums[right] == nums[right + 1] && right > left + 1);
              }else{
                  do{
                    left++;
                  }while(nums[left] == nums[left-1] && left + 1 < right);
              }
          }            
          }

        }
        return v;
    }
};


int main(){
  vector<int>  nums;
  nums = {-1,0,1,2,-1,-4};
  int target = -1;
  Solution solution;

  vector<vector<int> > result = solution.fourSum(nums, target);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[0].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }


    
  return 0;
}