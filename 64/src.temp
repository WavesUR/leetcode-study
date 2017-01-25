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
    int helper(vector<vector<int>>& grid, vector<vector<int>>& sum_val, int m, int n){
        if(m < 0 || n < 0) return INT_MAX;
        if(m == 0 && n == 0){
          return sum_val[m][n] = grid[m][n];
        }

        // if(m == 0){
        //   return sum_val[m][n] = helper(grid, sum_val,m,n-1) + grid[m][n];
        // }

        // if(n == 0){
        //   return sum_val[m][n] = helper(grid, sum_val,m-1,n) + grid[m][n];
        // }

        if(sum_val[m][n]>=0){
          return sum_val[m][n];
        }else{
          return sum_val[m][n] = min(helper(grid, sum_val,m,n-1), helper(grid, sum_val,m-1,n)) + grid[m][n];
        }

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum_val(m,vector<int>(n,-1));
        return helper(grid, sum_val,m-1,n-1);
    }
};

int main(){

  vector<vector<int> >  grid(5,vector<int>(6,-1));
  Solution solution;
  int result = solution.minPathSum(grid);
  // for(int i = 0; i<result.size();i++){
  //   cout << result[i] << endl;
  // }


    
  return 0;
}