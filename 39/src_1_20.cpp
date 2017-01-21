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

// Time: O()?
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int sum, int cur, vector<vector<int> >& res, vector<int>& v){

        if(sum == target){
          res.push_back(v);
          return;
        }

        
        for(int i = cur; i < candidates.size();i++){
          if(sum+candidates[i] > target){
            continue;
          }
          v.push_back(candidates[i]);
          backtrack(candidates,target,sum+candidates[i],i,res,v);
          v.pop_back();
        }
        

    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(candidates.empty()){
          return res;
        }

        int sum = 0;
        vector<int> v;
        int cur = 0;
        backtrack(candidates,target,sum,cur,res,v);
        return res;

    }
};

int main(){

  vector<int> nums(4);
  nums = {8,7,4,3};
  int target = 11;
  Solution solution;
  vector<vector<int> > result = solution.combinationSum(nums,target);
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