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
    void backtrack(vector<vector<int> >& res, vector<int>& nums, vector<int>& v, int cur, vector<int>& memo){
      if(cur == nums.size()){
        res.push_back(v);
        return;
      }

      for(int i = 0; i < nums.size();i++){
        if(memo[i] == 1) {
          continue;
        }
          memo[i] = 1;
          v.push_back(nums[i]);
          backtrack(res, nums,v,cur+1,memo);
          v.pop_back();
          memo[i] = 0;
      }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()){
            return res;
        }

        vector<int> v;
        int cur = 0;
        vector<int> memo;
        memo = vector<int>(nums.size(),0);
        backtrack(res, nums,v,cur,memo);
        return res;
    }
};


int main(){

  vector<int> nums(3);
  nums = {1 ,2 ,3};
  Solution solution;
  vector<vector<int> > result = solution.permute(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}