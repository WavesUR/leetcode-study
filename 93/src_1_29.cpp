#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;


class Solution {
public:
    void backtrack(string& s, vector<string>& res, string& t, int start, int section){
      if(section == 4){
        if(start == s.length()){
           t.pop_back();
           res.push_back(t);
        }
        return;
      }

      if(s[start] == '0'){
        string temp = t + (s[start]) + '.';
        backtrack(s,res,temp,start+1,section+1);
      }else if(s[start] == '1' || s[start] == '2'){
        for(int i = start; i < min(start + 3,(int)s.length()); i++){
          if(stoi(s.substr(start,i-start+1)) > 255){
            continue;
          }
          string temp = t + (s.substr(start,i-start+1)) + '.';
          backtrack(s,res,temp,i+1,section+1);      
        }
      }else{
         for(int i = start; i < min(start + 2,(int)s.length()); i++){
          string temp = t + (s.substr(start,i-start+1)) + '.';
          backtrack(s,res,temp,i+1,section+1);         
        }       
      }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() < 4){
          return res;
        }
        string t;
        int start = 0;
        int section = 0;
        backtrack(s,res,t,start,section);
        return res;
    }
};


int main(){


    string s = "1111";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    vector<string> result = solution.restoreIpAddresses(s);
    for(int i = 0; i < result.size();i++){
      cout << result[i] << endl;
    }
 //   cout<<s.substr(2,2);
    
  

    
	return 0;
}