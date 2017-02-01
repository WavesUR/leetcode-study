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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.empty()){
        return false;
      }
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
          if(matrix[i][j] == target){
            return true;
          }else if(matrix[i][j] > target){
            j--;
          }else{
            i++;
          }
        }
        return false;
      }
};

int main(){

  vector<vector<int> > matrix;
  matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
  int target = 19;
  Solution solution;
  bool result = solution.searchMatrix(matrix, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}