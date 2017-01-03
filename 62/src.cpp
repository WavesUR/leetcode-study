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
    vector<vector<int> > v;
    int dfs(int m, int n){
        if(m < 0 && n < 0){
          return 0;
        }
        if(m == 0 || n == 0){
          return 1;
        }
        return v[m][n] = dfs(m,n-1) + dfs(m-1,n);
    }
    int uniquePaths(int m, int n) {
      v = vector<vector<int> >(m, vector<int>(n,0));
      v[0][0] = 1;
      return dfs(m-1,n-1);
    }
};

int main(){

  int m = 5, n = 5;
  Solution solution;
  int result = solution.uniquePaths(m,n);


  cout << result << endl;

  return 0;
}