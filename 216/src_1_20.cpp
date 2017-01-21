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
    void backtrack(int k, int n, int cur, int sum, vector<vector<int> >& res, vector<int>& v){
      if(sum == n && k == 0){
        res.push_back(v);
        return;
      }
      if(k == 0){
        return;
      }
      for(int i = cur; i <= 9; i++){
        if(sum + i > n){
          break;
        }
        v.push_back(i);
        backtrack(k - 1, n, i + 1, sum + i, res, v);
        v.pop_back();
      }

    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if(k <= 0){
          return res;
        }
        int cur = 1;
        int sum = 0;
        vector<int> v;
        backtrack(k, n, cur, sum, res, v);
        return res;
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