#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int dp(vector<vector<int> >& memo, vector<int>& nums, int start, int end){
      if(start > end){
        return 0;
      }      
      if(memo[start][end] != -1){
        return memo[start][end];
      }
      // if(start == end){
      //   memo[start][end] = nums[start];
      //   return nums[start];
      // }

      int left = nums[start] + min(dp(memo,nums,start+1,end-1),dp(memo,nums,start+2,end));
      int right = nums[end] + min(dp(memo,nums,start,end-2),dp(memo,nums,start+1,end-1));
      memo[start][end] = max(left,right);
      return memo[start][end];
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > memo(nums.size(),vector<int>(nums.size(),-1));
        int sum = accumulate(nums.begin(),nums.end(),0);
        return 2*dp(memo,nums,0,nums.size()-1) >= sum ;
    }
};

int main(){

  vector<int> n = {1,5,233,7};
  Solution solution;
  bool result = solution.PredictTheWinner(n);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}