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
        int l = 0, r = m - 1, c;
        while(l<=r){
          c = (int)(l+(r-l)/2);
          // if(matrix[c][0] == target){
          //   return true;
          // }else 
          if(matrix[c][0] > target){
            r = c - 1;
          }else{
            l = c + 1;
          }
        }
        int k = l - 1; 
        l = 0; 
        r = n - 1;  
          while(l<=r){
          c = (int)(l+(r-l)/2);
          if(matrix[k][c] == target){
            return true;
          }else if(matrix[k][c] > target){
            r = c - 1;
          }else{
            l = c + 1;
          }
    }
    return false;
  }
};

int main(){

  vector<vector<int> > matrix(2,vector<int>(2,1));
  matrix = {{1,2},{3,4}};
  int target = 4;
  Solution solution;
  bool result = solution.searchMatrix(matrix, target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}