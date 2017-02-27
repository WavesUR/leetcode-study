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
    int dfs(vector<vector<int> >& matrix, vector<vector<int> >& memo, int i, int j, int pre){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] >= pre){
            return 0;
        }
        if(memo[i][j] > 0){
            return memo[i][j];
        }else{
            int cur = matrix[i][j];
            int temp = 0;
            temp = max(dfs(matrix,memo,i-1,j,cur),temp);
            temp = max(dfs(matrix,memo,i+1,j,cur),temp);
            temp = max(dfs(matrix,memo,i,j-1,cur),temp);
            temp = max(dfs(matrix,memo,i,j+1,cur),temp);
            memo[i][j]= ++temp;
            return memo[i][j];
        }

    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.empty()){
            return 0;
        }
        vector<vector<int> > memo(matrix.size(),vector<int>(matrix[0].size(),0));  
        int max_sum = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){        
                int temp = dfs(matrix,memo,i,j,INT_MAX);
                max_sum = max(temp,max_sum);
            }
        }
        return max_sum;
    }
};
int main(){

  vector<vector<int> > num = {{7,8,9},
                              {9,7,6},
                              {7,2,3}};
  Solution solution;
  int result = solution.longestIncreasingPath(num);

  cout << result << endl;


    
  return 0;
}