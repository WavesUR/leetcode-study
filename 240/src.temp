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
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()){
          return false;
        }        
        int m = matrix.size();
        int n = matrix[0].size();

        if(matrix[0][0] > target || matrix[m-1][n-1] < target){
          return false;
        }

//        cout << m << n << endl;
        int r = 0, c = n - 1;
        while(r < m && c >= 0){
          if(matrix[r][c] == target){
            return true;
          }else if(matrix[r][c] > target){
            c--;
          }else{
            r++;
          }
        }
        
    return false;
  }
};

int main(){

  vector<vector<int> > matrix(5,vector<int>(5,1));
  matrix = {{1,   4,  7, 11, 15},{2,   5,  8, 12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
  int target = 20;
  Solution solution;
  bool result = solution.searchMatrix(matrix, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}