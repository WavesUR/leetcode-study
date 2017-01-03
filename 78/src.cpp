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
    vector<vector<int> > subsets(vector<int>& nums) {
       vector<vector<int> > result;
       if(nums.empty()){
        return result;
       } 
       int n = nums.size(); 

       helper(nums, result, n);   
       return result;
    }
    void helper(vector<int>& nums, vector<vector<int> >& result, int n) {
      if(n == 0){
        result.push_back({});
        return;
      }
      helper(nums, result, n - 1);
      int s = result.size();
      for(int i = 0; i < s; i++){
        result.push_back(result[i]);
        result[s+i].push_back(nums[n-1]);
      }
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
  // cout << result << endl;


    
  return 0;
}