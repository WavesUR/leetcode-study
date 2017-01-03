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
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
      vector<vector<int> > result; 
        if(nums.empty()){
          return result;
        }
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;
        helper(nums, result, len, res);
        return result;
    }

    void helper(vector<int>& nums, vector<vector<int> >& result, int len, int& res){
        if(len == 0){
          result.push_back({});
          res = 1;
          return;
        }
        helper(nums, result, len - 1, res);
        int s = result.size();

        int start;
        if(len>=2 && nums[len-1] == nums[len-2]){
          start = s - res;
        }else{
          start = 0;
          res = s;
        }

        for(int i = start ; i < s; i++){
          vector<int> temp = result[i];
          temp.push_back(nums[len - 1]);
          result.push_back(temp);
        }
    }
};
int main(){

  vector<int> nums(3);
  nums = {3,3,3};
  Solution solution;
  vector<vector<int> > result = solution.subsetsWithDup(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  // cout << endl;
  // cout << result << endl;


    
  return 0;
}