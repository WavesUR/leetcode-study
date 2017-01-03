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
    void setZeroes(vector<vector<int> >& matrix) {
        if(matrix.empty()){
          return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        bool first_row_zero = false;
        bool first_col_zero = false;

        for(int i = 0; i < row; i++){
          if(matrix[i][0] == 0){
            first_col_zero = true;
            break;
          }
        }

        for(int i = 0; i < col; i++){
          if(matrix[0][i] == 0){
            first_row_zero = true;
            break;
          }
        }

        for(int i = 1; i < row; i++){
          for(int j = 1; j < col; j++){
            if(matrix[i][j] == 0){
              matrix[i][0] = 0;
              matrix[0][j] = 0;
            }
          }
        }

        for(int i = 1; i < col; i++){
          if(matrix[0][i] == 0){
            nullifycol(matrix,i);
          }
        }

        for(int i = 1; i < row; i++){
          if(matrix[i][0] == 0){
            nullifyrow(matrix,i);
          }
        }

        if(first_row_zero){
          nullifyrow(matrix,0);
        }

        if(first_col_zero){
          nullifycol(matrix,0);
        }
    }
    void nullifycol(vector<vector<int> >& matrix,int n){
      for(int i = 0; i < matrix.size(); i++){
          matrix[i][n] == 0;
      }
    }

    void nullifyrow(vector<vector<int> >& matrix,int n){
      for(int i = 0; i < matrix[0].size(); i++){
          matrix[n][i] == 0;
      }
    }

};

int main(){

  vector<vector<int> > matrix(2,vector<int>(2,1));
  matrix = {{1,2},{3,4}};
  Solution solution;
  solution.setZeroes(matrix);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  //cout << result << endl;


    
  return 0;
}