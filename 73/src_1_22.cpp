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
        bool first_row_zero = false;
        bool first_col_zero = false;
        for(int i = 0; i < matrix.size(); i++){
          if(matrix[i][0] == 0){
            first_col_zero = true;
            break;
          }
        }

        for(int i = 0; i < matrix[0].size(); i++){
          if(matrix[0][i] == 0){
            first_row_zero = true;
            break;
          }
        }
        for(int i = 0; i < matrix.size();i++){
          for(int j = 0; j < matrix[0].size();j++){
            if(matrix[i][j] == 0){
              matrix[i][0] = 0;
              matrix[0][j] = 0;
              break;
            }
          }
        }
        for(int i = 1; i < matrix.size(); i++){
          if(matrix[i][0] == 0){
            for(int j = 1; j < matrix[0].size();j++){
              matrix[i][j] = 0;
            }
          }
        }
        for(int i = 1; i < matrix[0].size(); i++){
          if(matrix[0][i] == 0){
            for(int j = 1; j < matrix.size();j++){
              matrix[j][i] = 0;
            }
          }
        }
        if(first_row_zero){
            for(int j = 0; j < matrix[0].size();j++){
              matrix[0][j] = 0;
            }
        }
        if(first_col_zero){
            for(int j = 0; j < matrix.size();j++){
              matrix[j][0] = 0;
            }
        }
    }
};

int main(){

  vector<vector<int> > matrix;
  matrix = {{1,0,2},{3,4,6},{2,3,4}};
  Solution solution;
  solution.setZeroes(matrix);
          for(int i = 0; i < matrix.size();i++){
          for(int j = 0; j < matrix[0].size();j++){
            cout << matrix[i][j] << " ";
            }
            cout << endl;
          }
      
    
  return 0;
}