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
    void backtrack(vector<int>& candidates, int target, int cur, int sum, vector<vector<int> >& res, vector<int>& v){
        if(sum == target){
          res.push_back(v);
          return;
        }

        for(int i = cur; i < candidates.size(); i++){
          if(sum + candidates[i] > target){
            break;
          }          
          if(i > cur && candidates[i] == candidates[i - 1]){
            continue;
          }

          v.push_back(candidates[i]);
          backtrack(candidates, target,i + 1, sum + candidates[i], res,v);
          v.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(candidates.empty()){
          return res;
        }
        sort(candidates.begin(),candidates.end());
        int cur = 0;
        int sum = 0;
        vector<int> v;
        backtrack(candidates, target,cur, sum, res,v);
        return res;
    }
};

int main(){

  vector<int> nums;
  nums = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  Solution solution;
  vector<vector<int> > result = solution.combinationSum2(nums,target);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }


    
  return 0;
}