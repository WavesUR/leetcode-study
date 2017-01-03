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
        if(n < 1){
          vector<vector<int> > result;
          return result;
        }      
        vector<vector<int> > result(n,vector<int>(n,0));

        int temp = 1;
        for(int i = 0; i < n; i++){
          for(int j = i; j < n - i - 1; j++){
            result[i][j] = temp;
            temp++;
          }
          for(int j = i; j < n - i - 1; j++){
            result[j][n-i-1] = temp;
            temp++;
          }
          for(int j = n - i - 1; j > i; j--){
            result[n-i-1][j] = temp;
            temp++;
          }
          for(int j = n - i - 1; j > i; j--){
            result[j][i] = temp;
            temp++;
          }
        }
        if(n%2==1){
          result[n/2][n/2] = temp;
        }

        return result;
    }
};


int main(){
int n = 4;
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