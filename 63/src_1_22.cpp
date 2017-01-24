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
    int dp(vector<vector<int>>& obstacleGrid, int row, int col, int m, int n, vector<vector<int> >& path){
      if(row >= m || col >= n || obstacleGrid[row][col] == 1){
        return 0;
      }

      if(row == m-1 && col == n-1){
        return 1;
      }

      if(path[row][col]>=0){
        return path[row][col];
      }else{
        return path[row][col] = dp(obstacleGrid,row+1,col,m,n,path) + dp(obstacleGrid,row,col+1,m,n,path);
      }

    }
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {

        if(obstacleGrid.back().back() == 1 || obstacleGrid[0][0] == 1){
          return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > path;
        path = vector<vector<int> >(m, vector<int>(n,INT_MIN));
        return dp(obstacleGrid,0,0,m,n,path);
    }
};

int main(){
  vector<vector<int> > nums;
  nums = {{0,0,0},{0,1,0},{0,0,0}};
  Solution solution;
  int result = solution.uniquePathsWithObstacles(nums);
  // for(int i = 0; i < nums.size(); i++){
  //   for(int j = 0; j < nums[0].size(); j++){
  //     cout << solution.v[i][j] << " ";
  //   }
  //   cout << endl;
  //}
  cout << result << endl;


    
  return 0;
}