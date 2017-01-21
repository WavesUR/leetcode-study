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

//Time: O(mn)!!!
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int island = 0;
        int next = 0;
        for(int r = 0; r < grid.size(); r++){
          for(int c = 0; c < grid[0].size(); c++){
            if(grid[r][c] == 1){
              island++;
              //only check its left and upper sides
              if(c != 0 && grid[r][c-1] == 1){
                next++;
              }
              if(r != 0 && grid[r-1][c] == 1){
                next++;
              }
            }
          }
        }
        return 4*island - 2*next;
    }
};
int main(){

  vector<vector<int> > nums;
  nums = {{0,1,0,0},
 {1,1,1,0},
 {0,1,0,0},
 {1,1,0,0}};
  Solution solution;
  int result = solution.islandPerimeter(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}