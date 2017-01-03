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
    vector<vector<string> > partition(string s) {
        vector<vector<string> > vv;
        int len = s.length();
        if(len == 0){
            return vv;
        }
        vector<string> v;
        int cur_s = 0;
        int cur_l = 0;
        helper(vv,v,s,cur_l, cur_l);
        return vv;
    }

    void helper(vector<vector<string> >& vv, vector<string>& v, string & s, int cur_s, int cur_l){
      if(cur_l == s.length() - 1){
        if(isp(s,cur_s,cur_l)){
          v.push_back(s.substr(cur_s, cur_l-cur_s+1));
          vv.push_back(v);
          v.pop_back();
        }
        return;
      }
//      cout << cur_s << endl;
      if(isp(s, cur_s, cur_l)){
        v.push_back(s.substr(cur_s, cur_l-cur_s+1));
        helper(vv,v,s,cur_l+1, cur_l+1);
        v.pop_back();

      }
        helper(vv,v,s,cur_s, cur_l+1);
      


    }

    bool isp(string & s, int cur_s, int cur_l){
      while(cur_s <= cur_l){
        if(s[cur_s] != s[cur_l]){
          return false;
        }
        cur_s++;
        cur_l--;
      }
      return true;
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