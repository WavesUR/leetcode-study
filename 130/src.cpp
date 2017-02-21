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
    void solve(vector<vector<char> >& board) {
        
    }
};

int main(){

  vector<vector<char> > grid;
  // grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    grid = {{'X','X','X','X'},
            {'X','0','0','X'},{
             'X','X','0','X'},
             {'X','0','X','X'}};
  Solution solution;
  int result = solution.solve(grid);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
   cout << result << endl;


    
  return 0;
}