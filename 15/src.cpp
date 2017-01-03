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
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int len = nums.size();
        if(len < 3){
          return result;
        }
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i < len - 2){
           int left = i + 1;
           int right = len - 1; 
           while(left < right && nums[i] <= 0){
              int sum = nums[i] + nums[left] + nums[right];
              if(sum == 0){
                  vector<int> temp = {nums[i],nums[left],nums[right]};
//                  if(result.empty() || temp != result[result.size() - 1]){
                    result.push_back(temp);
//                  }
                  
                                    do{
                    left++;
                    }while(nums[left] == nums[left-1]);
                                      do{
                  right--;
                  }while(nums[right] == nums[right+1]);             
                }else if(sum < 0){
                  do{
                    left++;
                    }while(nums[left] == nums[left-1]);
                }else{
                  do{
                  right--;
                  }while(nums[right] == nums[right+1]);  
                }

         
           }             
                  do{
                  i++;
                  }while(nums[i] == nums[i-1]);  
                      
        }
        return result;
    }
};


int main(){
  vector<int> nums;
  nums = {0,0,0,0};
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