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
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> sum(grid[0].size(),grid[0][0]);
        for(int j = 1; j < grid[0].size();j++){
          sum[j] = sum[j-1] + grid[0][j];
        }
        for(int i = 1; i < grid.size();i++){
          sum[0] = sum[0] + grid[i][0]; 
          for(int j = 1; j < grid[0].size();j++){
              sum[j] = min(sum[j-1],sum[j]) + grid[i][j];            
          }
        }
        return sum.back();
    }
};
int main(){

  vector<vector<int> >  grid(5,vector<int>(6,1));
  Solution solution;
  int result = solution.minPathSum(grid);
  cout << result << endl;
    
  return 0;
}