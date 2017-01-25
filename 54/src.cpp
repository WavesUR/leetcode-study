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
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;      
      if(matrix.empty()){
        return res;
      }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        
        while(left <= right && top <= bottom){
          for(int i = left; i <= right;i++){
            res.push_back(matrix[top][i]);
          }
          top++;
          for(int i = top; i <= bottom; i++){
            res.push_back(matrix[i][right]);
          }
          right--;
          if(top <= bottom){
            for(int i = right; i >= left; i--){
              res.push_back(matrix[bottom][i]);
            }            
          }
          bottom--;
          if(left <= right){
            for(int i = bottom; i >= top; i--){
              res.push_back(matrix[i][left]);
            }            
          }
          left++;
        }
        return res;
    }
};
int main(){

  vector<vector<int> >  grid;
  grid = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25},{26, 27, 28, 29, 30}};
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size();j++){
        cout << grid[i][j] << " ";
      }      
      cout << endl;
    }
  Solution solution;
  vector<int> result = solution.spiralOrder(grid);
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
    }
  return 0;
  
}