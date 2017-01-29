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
    bool ispp(string str){
      if(str.length() == 1){
        return true;
      }

      int start = 0;
      int end = str.length() - 1;
      while(start < end){
        if(str[start] != str[end]){
          return false;
        }
        start++;
        end--;
      }
      return true;


    }
    void backtrack(string s, vector<vector<string> >& res, vector<string>& v, int cur){
        if(cur == s.length()){
          res.push_back(v);
          return;
        }

        for(int i = cur; i < s.length(); i++){
          if(ispp(s.substr(cur,i-cur+1))){
            v.push_back(s.substr(cur,i-cur+1));
            backtrack(s, res, v, i + 1);
            v.pop_back();
          }
        }

    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> v;
        int cur = 0;
        backtrack(s,res,v,cur);
        return res;
    }
};

int main(){

  string s = "aab";
  Solution solution;
  vector<vector<string> > result = solution.partition(s);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}