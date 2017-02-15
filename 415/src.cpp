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
    string addStrings(string num1, string num2) {
        string res = "";
        int cur1 = num1.length() - 1;
        int cur2 = num2.length() - 1;
        int carry = 0;
        while(cur1 >= 0 || cur2 >= 0 || carry != 0){
          int a = cur1 >= 0 ? num1[cur1] - '0' : 0;
          int b = cur2 >= 0 ? num2[cur2] - '0' : 0;
          int c = a + b + carry;
          carry = c / 10;
          res = char(c%10+'0')+res;
          cur1--;
          cur2--;
        }
        return res;
    }
};

int main(){

  string num1 = "1";
  string num2 = "9";
  Solution solution;
  string result = solution.addStrings(num1,num2);

  cout << result << endl;


    
  return 0;
}