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
    int getMoneyAmount(int n) {
//        int table[n+1][n+1] = {0};
      vector<vector<int> > table(n+1,vector<int>(n+1,0));
        return helper(table,1,n);
    }
    int helper(vector<vector<int> >& table, int start, int last){
      if(start >= last){
        return 0;
      }
      if(table[start][last]!=0){
        return table[start][last];
      }
      int min_val = INT_MAX;
      for(int i = start; i <= last; i++){
        int temp = i + max(helper(table, start, i-1), helper(table, i+ 1,last));
        min_val = min(temp,min_val);
      }

      return table[start][last] = min_val;

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