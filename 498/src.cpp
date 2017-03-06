#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        vector<int> res;      
        if(matrix.empty()){
          return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        for(int d = 0; d < m + n - 1; d++){
          if(d%2 == 0){
            for(int i = min(d,m-1); (i >= 0) && d-i <= n -1; i--){
              // cout << i << " " << d - i << endl;
            res.push_back(matrix[i][d-i]);
            }
          }else{
            for(int j = min(d,n-1); (j >=0)  && d-j <= m -1; j--){
              // cout << d- j << " " << j << endl;
            res.push_back(matrix[d-j][j]);
            }
          }
        }
        return res;
    }
};
int main(){

  vector<vector<int> > matrix = {{2,5,8},{4,5,6}};
  Solution solution;
  vector<int> result = solution.findDiagonalOrder(matrix);

  for(auto r : result){
    cout << r << endl;
  }


    
  return 0;
}