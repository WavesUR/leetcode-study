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
    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& v, vector<int>& memo, int cur){
          if(cur == nums.size()){
            res.push_back(v);
            return;
          }

          for(int i = 0; i < nums.size();i++){
            
            if(memo[i] == 1){
              continue;
            }
            if(i > 0 && nums[i] == nums[i - 1] && memo[i - 1] == 0){
              continue;
            }
            memo[i] = 1;
            v.push_back(nums[i]);
            backtrack(nums,res,v,memo,cur+1);
            v.pop_back();
            memo[i] = 0;
          }

    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()){
          return res;
        }
        sort(nums.begin(),nums.end());
        int cur = 0;
        vector<int> v;
        vector<int> memo;
        memo = vector<int>(nums.size(),0);
        backtrack(nums,res,v,memo,cur);
        return res;

    }
};

int main(){

  vector<int> nums;
  nums = {1,2,3};
  Solution solution;
  vector<vector<int> > result = solution.permuteUnique(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}