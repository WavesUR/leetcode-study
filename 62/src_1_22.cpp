#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    int dp(int m,int n, int row, int col, vector<vector<int> >& path){
        if(row >= m  || col >= n){
          return 0;
        }

        if(row == m - 1 || col == n - 1){
          path[row][col] = 1;
          return 1;
        }

        if(path[row][col]){
          return path[row][col];
        }else{
          return path[row][col] = dp(m,n,row+1,col,path) + dp(m,n,row,col+1,path);
        }

    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > path;
        path = vector<vector<int> >(m, vector<int>(n,0));
        return dp(m,n,0,0,path);
    }
};

int main(){

  int m = 3, n = 2;
  Solution solution;
  int result = solution.uniquePaths(m,n);


  cout << result << endl;

  return 0;
}