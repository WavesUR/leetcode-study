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
#include <utility>
using namespace std;



class Solution {
public:
    string dfs(string s, int& start){

      int num = 0;
      string res;
      while(start < s.length()){
        if(isdigit(s[start])){
          num = num*10+s[start] - '0';
        }else if(s[start] == '['){
          string t = dfs(s, ++start);
          for(int j = 0; j < num; j++){
            res = res + t;          
          }
          num = 0;
        }else if(s[start] == ']'){
          return res;
        }else{
          res = res + s[start];
        }
        start++;
      }
      return res;
    }

    string decodeString(string s) {
        int i = 0;       
        return dfs(s,i);
    }
};

int main(){

  string s  = "3[a]2[bc]";
  Solution solution;
  string result = solution.decodeString(s);

 cout << result << endl;


    
  return 0;
}