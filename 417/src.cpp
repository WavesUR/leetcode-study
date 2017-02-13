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
#include <utility>
using namespace std;



class Solution {
public:
    void dfs(vector<vector<int> >& matrix, int i, int j, int m, int n, int height, vector<vector<bool> >& memo){
      if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] < height || memo[i][j]){
        return;
      }
      memo[i][j] = true;
      dfs(matrix,i+1,j,m,n,matrix[i][j],memo);
      dfs(matrix,i-1,j,m,n,matrix[i][j],memo);
      dfs(matrix,i,j+1,m,n,matrix[i][j],memo);
      dfs(matrix,i,j-1,m,n,matrix[i][j],memo);
    }
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<pair<int,int> > res;
        if(matrix.empty()){
          return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool> > p(m,vector<bool>(n,false));
        vector<vector<bool> > a(m,vector<bool>(n,false));
        for(int i = 0; i < m; i++){
          dfs(matrix,i,0,m,n,INT_MIN,p);
          dfs(matrix,i,n-1,m,n,INT_MIN,a);
        }
        for(int i = 0; i < n; i++){
          dfs(matrix,0,i,m,n,INT_MIN,p);
          dfs(matrix,m-1,i,m,n,INT_MIN,a);
        }
        for(int i = 0; i < m;i++){
          for(int j = 0; j < n; j++){
            if(p[i][j] && a[i][j]){
              res.push_back(make_pair(i,j));
            }
          }
        }
        return res;
    }
};

int main(){

  vector<vector<int> > nums = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  Solution solution;
  vector<pair<int, int> > result = solution.pacificAtlantic(nums);

  for(auto re : result){
    cout << re.first << " " << re.second << endl;
  }


    
  return 0;
}