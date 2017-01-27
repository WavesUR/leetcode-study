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
    void backtrack(string digits, string& s, vector<string>& digits_map, vector<string>& v,int cur){
        if(cur == digits.length()){
          v.push_back(s);
          return;
        }

        for(int i = 0; i < digits_map[digits[cur]-'0'].size(); i++){
          s.push_back(digits_map[digits[cur]-'0'][i]);
          backtrack(digits, s, digits_map, v, cur+1);
          s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length() == 0){
          return v;
        }
        vector<string> digits_map = {" ", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;

        int cur = 0;
        backtrack(digits, s, digits_map, v, cur);
        return v;
    }
};

int main(){


    string digits = "";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);
    for(int i = 0; i < result.size(); i++){
      cout << result[i] << endl;
    }
    


    
	return 0;
}