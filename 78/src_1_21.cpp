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
    void backtrack(vector<int>& nums, vector<vector<int> >& res, vector<int>& v, int cur){
      if(cur == nums.size()){
        res.push_back(v);
        return;
      }

      
        v.push_back(nums[cur]);
        backtrack(nums,res,v,cur+1);
        v.pop_back();
        backtrack(nums,res,v,cur+1);
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> v;
        int cur = 0;
        backtrack(nums,res,v,cur);
        return res;
    }
};

int main(){

  vector<int> nums(3);
  nums = {1,2,3};
  Solution solution;
  vector<vector<int> > result = solution.subsets(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  // cout << endl;
   cout << result.size() << endl;


    
  return 0;
}