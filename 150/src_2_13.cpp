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
    int evalRPN(vector<string>& tokens) {
      if(tokens.empty()){
        return 0;
      }
      stack<int> s;
      for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
          int b = s.top();
          s.pop();
          int a = s.top();
          s.pop();
          int result;
          if(tokens[i] == "+"){
            result = a + b;
          }else if(tokens[i] == "-"){
            result = a - b;
          }else if(tokens[i] == "*"){
            result = a * b;
          }else{
            result = a / b;
          }
          s.push(result);
        }else{
          s.push(stoi(tokens[i]));
        }
      }
      return s.top();

    }
};

int main(){


    vector<string> str1 = {"2", "1", "+", "3", "*"};
    Solution solution;
    int result = solution.evalRPN(str1);
    cout << result << endl;


    
	return 0;
}