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
    int dp(vector<vector<int> >& memo, int start, int end){
      if(start >= end){
        return 0; //in [start end], the cost is 0, because you must guess right
      }

      if(memo[start][end] != 0){
        return memo[start][end];
      }

      int min_val = INT_MAX;
      for(int i = start; i <= end; i++){
        int temp = i + max(dp(memo,start,i-1), dp(memo,i+1,end));
        min_val = min(min_val,temp);
      }
      memo[start][end] = min_val;
      return min_val;

    }
    int getMoneyAmount(int n) {
        vector<vector<int> > memo(n+1,vector<int>(n+1,0));
        return dp(memo,1,n);

    }
};

int main(){

  int n = 3;
  Solution solution;
  int result = solution.getMoneyAmount(n);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}