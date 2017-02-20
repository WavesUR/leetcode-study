#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> my_s;
        int num = 0;
        char sign = '+';
        for(int i = 0 ; i < s.length(); i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1){
                if(sign == '+'){
                    my_s.push(num);
                }else if(sign == '-'){
                    my_s.push(-num);
                }else if (sign == '*'){
                    int temp = my_s.top();
                    my_s.pop();
                    my_s.push(temp*num);
                }else if (sign == '/'){
                    int temp = my_s.top();
                    my_s.pop();
                    my_s.push(temp/num);
                }  
                sign = s[i];
                num = 0;          
            }

        }
        int res = 0;
        while(!my_s.empty()){
            res = res + my_s.top();
            my_s.pop();
        }
        return res;
    }
};



int main(){

  string s = " 3+5 / 2 ";
  Solution solution;
  int result = solution.calculate(s);
  cout << result << endl;


    
  return 0;
}