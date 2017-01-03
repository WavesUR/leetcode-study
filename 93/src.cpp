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
    vector<string> restoreIpAddresses(string s) {
        string temp;
        vector<string> v;
        if(s.length() < 4){
          return v;
        }
        int section = 0;
        int n = 0;
        helper(v, s, temp, n, section);
        return v;


    }

    void helper(vector<string>& v, string& s, string& temp, int n, int section){
      if(section == 3){
        int sect = atoi(s.c_str()+n);
        string temp_s = s.substr(n);
        if(sect >= 0 && sect <=255 && !(temp_s.length() > 1 && temp_s[0]=='0')){
          v.push_back(temp+temp_s);
        }        
        return;
      }

      for(int i = 0; i < 3 && n + i < s.length() - 1; i++){
        string temp_s = s.substr(n,i+1);
        if(temp_s.length() > 1 && temp_s[0]=='0'){
          return;
        }

        int sect = atoi(temp_s.c_str());       
        if(sect >= 0 && sect <=255){
          string temp1 = temp;
          temp = temp+temp_s + ".";
          helper(v, s, temp, n+i+1, section+1);
          temp = temp1;
        } 
      }
    }
};


int main(){


    string s = "010010";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    vector<string> result = solution.restoreIpAddresses(s);
    for(int i = 0; i < result.size();i++){
      cout << result[i] << endl;
    }
 //   cout<<s.substr(2,2);
    
  

    
	return 0;
}