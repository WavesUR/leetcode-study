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
        int left = 0, right = matrix.size() - 1, mid;
        //last vaild one
        while(left < right){
          mid = left + (right - left) / 2 + 1;
          if(matrix[mid][0] == target){
            return true;
          }else if(matrix[mid][0] < target){
            left = mid;
          }else{
            right = mid - 1;
          }
        }
        int row = left;
        left = 0, right = matrix[0].size() - 1;
        while(left <= right){
          mid = left + (right - left) / 2;
          if(matrix[row][mid] == target){
            return true;
          }else if(matrix[row][mid] > target){
            right = mid - 1;
          }else{
            left = mid + 1;
          }
        }
        return false;
    }
};

int main(){

  vector<vector<int> > matrix;
  matrix = {  {1,   3,  5,  7},
  {10, 11, 16, 20},
  {23, 30, 34, 50}};
  int target = 4;
  Solution solution;
  bool result = solution.searchMatrix(matrix, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}