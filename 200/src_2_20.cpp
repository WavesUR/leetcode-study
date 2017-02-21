#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <queue>
using namespace std;


class Solution {
public:
    void DFS(vector<vector<char> >& grid, int i, int j){
      if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1' ){
        return;
      }
      grid[i][j] = '0';
      DFS(grid,i+1,j);
      DFS(grid,i,j+1);
      DFS(grid,i-1,j);
      DFS(grid,i,j-1);
    }
    int numIslands(vector<vector<char> >& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
          for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
              sum++;
              DFS(grid,i,j);
            }
          }
        }
        return sum;
    }
};

int main(){

  vector<vector<char> > grid;
  // grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    grid = {{'1','1','1'},
            {'0','1','0'},{
             '1','1','1'}};
  Solution solution;
  int result = solution.numIslands(grid);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
   cout << result << endl;


    
  return 0;
}