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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if(candidates.empty()){
          return result;
        }
        vector<int> path;
        int start = 0;
        helper(candidates, target, start, result, path);
        return result;

    }

    void helper(vector<int>& candidates, int gap, int start, vector<vector<int> >& result, vector<int>& path){
        if(gap == 0){
          result.push_back(path);
          return;
        }

        for(int i = start; i < candidates.size();i++){
          if(gap < candidates[i]){
            continue;
          }
          path.push_back(candidates[i]);
          helper(candidates, gap-candidates[i], i, result, path);
          path.pop_back();
        }

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