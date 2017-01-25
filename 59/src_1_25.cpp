#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        if(n == 0){
          return res;
        }
        res = vector<vector<int> >(n,vector<int>(n,0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int temp = 1;
        while(temp <= n * n){
          for(int i = left; i <= right; i++){
            res[top][i] = temp;
            temp++;
          }
          top++;
          for(int i = top; i <= bottom; i++){
            res[i][right] = temp;
            temp++;
          }
          right--;
              for(int i = right; i >= left; i--){
              res[bottom][i] = temp;
              temp++;
            }

          bottom--;
            for(int i = bottom; i >= top; i--){
              res[i][left] = temp;
              temp++;
            }            
          left++;
        }

        return res;
    }
};


int main(){
int n = 1;
Solution solution;
vector<vector<int> > result = solution.generateMatrix(n);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }

    
return 0;
}