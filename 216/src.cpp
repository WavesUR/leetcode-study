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
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;

        vector<int> v;
        helper(result, v, k, n, 1);
        return result;
    }
    void helper(vector<vector<int> > &result, vector<int> & v, int k , int n, int i){
        if(k == 0){
          if(n == 0){
            result.push_back(v);
          }
          return;
        }

        while(i <= 9 - k + 1){
          if(i <= n){
            v.push_back(i);
            helper(result, v, k -1, n - i, i + 1);
            v.pop_back();
          }
          i++;
        }



    }
};

int main(){


  int k = 3;
  int n = 9;
  Solution solution;
  vector<vector<int> > result = solution.combinationSum3(k,n);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  // cout << endl;
  // cout << result << endl;


    
  return 0;
}