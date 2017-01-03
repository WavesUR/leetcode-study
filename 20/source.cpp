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
       int i = 0;
       stack<char> mystack;
       while(i < s.length()){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
          mystack.push(s[i]);
        }else if(!mystack.empty() && (s[i] - mystack.top() == 1 || s[i] - mystack.top() == 2)){
          mystack.pop();
        }else{
          return false;
        }
        i++;
       }
       return mystack.empty() ? true : false;
    }
};

int main(){


    string str1 = "]";
    Solution solution;
    bool result = solution.isValid(str1);
    cout << result << endl;
    cout << str1[1]-str1[0] << endl;


    
	return 0;
}