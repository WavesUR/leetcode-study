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
#include <utility>
using namespace std;


class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int> >& res,vector<int>& v, int cur){
      if(cur == nums.size()){
        if(v.size() >= 2){
          res.push_back(v);
        }
        return;
      }
      if(v.size() >= 2){
        res.push_back(v);
      }

      unordered_map<int,bool> my_map;
      for(int i = cur; i < nums.size(); i++){
        if(v.size() != 0 && nums[i] < v.back()){
          continue;
        }
        if(my_map[nums[i]] == false){
          v.push_back(nums[i]);
          dfs(nums, res, v, i+1);
          v.pop_back();
          my_map[nums[i]] = true;
        }

      }

    }
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()){
          return res;
        }
        vector<int> v;
        dfs(nums, res, v, 0);
        return res;
    }
};

int main(){

  vector<int> nums = {100,90,80,70,60,50,60,70,80,90,100};
  Solution solution;
  vector<vector<int> > result = solution.findSubsequences(nums);

  for(auto vv : result){
    for(auto v:vv){
      cout << v << " ";
    }
      cout << endl;
  }


    
  return 0;
}