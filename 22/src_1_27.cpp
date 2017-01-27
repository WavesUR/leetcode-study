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
    void backtrack(int n, vector<string>& res, string& s, int cur, int num){
      if(cur == n * 2){
        if(num == 0){
          res.push_back(s);
        }        
        return;
      }
      if(num == 0){
        s.push_back('(');
        backtrack(n,res,s,cur+1,num+1);
        s.pop_back();
      }else{
        s.push_back('(');
        backtrack(n,res,s,cur+1,num+1);
        s.pop_back();
        s.push_back(')');
        backtrack(n,res,s,cur+1,num-1);
        s.pop_back();
      }



    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0){
          return res;
        }
        string s;
        int cur = 0;
        int num = 0;
        backtrack(n,res,s,cur,num);
        return res;

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