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
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > vv;
        if(candidates.empty()){
          return vv;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        helper(candidates,target, 0,vv,v);
        return vv;
    }

    void helper(vector<int>& candidates, int target, int cur, vector<vector<int> >& vv, vector<int>& v){
      int len = candidates.size();
      // cout << cur << endl;
        if(cur == len - 1){
          if(candidates[cur] != target){
            return;
           }
        }
        if(candidates[cur] > target){
          return;
        }else if(candidates[cur] == target){
            v.push_back(candidates[cur]);
            vv.push_back(v);
            v.pop_back();
            return;
        }else{
          int temp = candidates[cur];
          v.push_back(temp);
//          for(int i = cur + 1; i < len; i++){
            helper(candidates,target-temp, cur+1, vv,v);
//          }            
          v.pop_back();
          int i = cur+1;
          while(candidates[i] == candidates[i-1]){
              i++;             
          } 
          helper(candidates,target, i, vv,v);
        }
    }
};

int main(){

  vector<int> nums;
  nums = {3,3,5,5,3,3,5,3,3,3,4};
  int target = 10;
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