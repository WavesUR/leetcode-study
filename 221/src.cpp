#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.empty()){
          return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int max_val = 0;
        vector<vector<int> > memo(m,vector<int>(n,0));
        for(int i = m - 1; i >= 0; i--){
          memo[i][n-1] = matrix[i][n-1] - '0';
          max_val = max(max_val,memo[i][n-1]);
        }
        for(int i = n - 2; i >= 0; i--){
          memo[m-1][i] = matrix[m-1][i] - '0';
           max_val = max(max_val,memo[m-1][i]);
        }
        for(int i = m - 2; i >= 0; i--){
          for(int j = n - 2; j >= 0; j--){
            if((matrix[i][j] - '0') && memo[i][j+1] && memo[i+1][j] && memo[i+1][j+1]){
              memo[i][j] = min(memo[i][j+1],min(memo[i+1][j],memo[i+1][j+1]) )+ 1;

            }else{
              memo[i][j] = matrix[i][j] - '0';
            }
            max_val = max(max_val,memo[i][j]);
          }
        } 
        return max_val*max_val;
    }
};
int main(){

  vector<vector<char> > matrix;
  matrix = {{'0','0','0','0'},
            {'1','1','0','1'},
            {'1','1','1','1'},
            {'0','1','1','1'},
            {'0','1','1','1'}};
  string s = "leetcode";
  Solution solution;
  int result = solution.maximalSquare(matrix);
  cout << result << endl;


    
  return 0;
}