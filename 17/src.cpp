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
    vector<string> digits_map;
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        digits_map = {{" "},{""},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
        if(!digits.length()){
          return v;
        }
        string s;
        int level = 0;
        helper(v, s, level, digits);
        return v;
    }
    void helper(vector<string>& v, string& s, int level, string& digits){
      if(level == digits.length()){
        v.push_back(s);
        return;
      }
//      for(int i = level; i < digits.length(); i++){
        int digits_i = digits[level]-'0';
        for(int j = 0; j < digits_map[digits_i].length(); j++){
          s.push_back(digits_map[digits_i][j]);
          helper(v,s,level + 1, digits);
          s.pop_back();
        }
 //     }
    }
};

int main(){


    string digits = "03";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);
    for(int i = 0; i < result.size(); i++){
      cout << result[i] << endl;
    }
    


    
	return 0;
}