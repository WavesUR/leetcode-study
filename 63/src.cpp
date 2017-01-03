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
    vector<vector<int> > v;
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
         int m = obstacleGrid[0].size();
         int n = obstacleGrid.size();

        // cout << n << m << obstacleGrid[2][2]<<endl;
         if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1]){
            return 0;
         }
         v = vector<vector<int> >(n, vector<int>(m,INT_MIN));
         v[0][0] = 1;
         return obstacleGrid[n-1][m-1] == 1 ? 0 : helper(n-1,m-1,obstacleGrid); //: helper(n-1,m-1,obstacleGrid);
    }

    int helper(int n, int m, vector<vector<int> >& obstacleGrid){
        if(n < 0 || m < 0){
          return 0;
        }    
        if(obstacleGrid[n][m]){
          return v[n][m] = 0;
        }   
        if(n == 0 && m == 0){
          return v[0][0];
        }
        
        if(v[n][m]>=0){
          return v[n][m];
        }else{
          int temp1 = helper(n-1,m,obstacleGrid);
          int temp2 = helper(n,m-1,obstacleGrid);
          return v[n][m] = temp1+temp2;
        }

    }
};

int main(){
  vector<vector<int> > nums;
  nums = {{0,0},{1,1},{0,0}};
  Solution solution;
  int result = solution.uniquePathsWithObstacles(nums);
  for(int i = 0; i < nums.size(); i++){
    for(int j = 0; j < nums[0].size(); j++){
      cout << solution.v[i][j] << " ";
    }
    cout << endl;
  }
  cout << result << endl;


    
  return 0;
}