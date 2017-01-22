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

// top to bottom
// class Solution {
// public:
//     int dp(vector<vector<int> >& triangle, int row, int col){
//         if(row == triangle.size() - 1){
//           return triangle[row][col];
//         }else{
//           return triangle[row][col] + min(dp(triangle,row+1,col), dp(triangle,row+1,col+1));
//         }
//     }
//     int minimumTotal(vector<vector<int> >& triangle) {
//         return dp(triangle,0,0);
//     }
// };

// bottom to top
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int len = triangle.size();
        vector<int> path = triangle[len -1];
        for(int row = len - 2; row >= 0; row--){
          for(int col = 0; col <= row; col++ ){
            path[col] = triangle[row][col] + min(path[col],path[col+1]);
          }
        }
        return path[0];
    }
};

int main(){

  vector<vector<int> > nums;
  nums = {{2},{3,4},{6,5,7},{4,1,8,3}};
  Solution solution;
  int result = solution.minimumTotal(nums);

  cout << result << endl;


    
  return 0;
}