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
    bool isValid(string s) {
        int len = s.length();
        if(len%2 != 0){
          return false;
        }
        stack<char> my_stack;
        for(int i = 0; i < len; i++){
          if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            my_stack.push(s[i]);
          }else if(!my_stack.empty()){
            char t = my_stack.top();
            if((s[i] == ')' && t == '(') || (s[i] == '}' && t == '{') ||( s[i] == ']' && t == '[')){
              my_stack.pop();
            }else{
              my_stack.push(s[i]);
            }
          }else{
            return false;
          }
        }
        return my_stack.empty();
    }
};

int main(){


    string str1 = "([[])";
    Solution solution;
    bool result = solution.isValid(str1);
    cout << result << endl;


    
	return 0;
}