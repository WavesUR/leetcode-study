#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        helper(temp,result,1,k,n);
        return result;
    }

    void helper(vector<int>& temp, vector<vector<int> >& result, int start,int k,int n){
      if(k == 0){
        result.push_back(temp);
        return;
      }

      for(int i = start; i <= n -k + 1; i++){
          temp.push_back(i);
          helper(temp,result,i+1,k-1,n);
          temp.pop_back();
      }
    }
};
int main(){

  int n = 4;
  int k = 2;
  Solution solution;
  vector<vector<int> > result = solution.combine(n, k);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}