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
    void helper(vector<string> & v, string s, int l, int r) {
      if(l == 0 && r == 0){
        v.push_back(s);
        return;
      }
//      cout << l << endl;
      if(l > 0){
        helper(v, s + "(", l-1, r);
      }


      if(r > 0 && r > l){
        helper(v, s + ")", l, r-1);
      }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        helper(v, s, n, n);
        return v;
    }
};

int main(){

  int n = 3;
  vector<string> result;
  Solution solution;
  result = solution.generateParenthesis(n);
  for(int i = 0; i<result.size();i++){
    cout << result[i] << endl;
  }


    
  return 0;
}