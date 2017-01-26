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
    string addBinary(string a, string b) {
        int c = 0;
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        while(i >= 0 || j >= 0 || c == 1){
          int op_a = i >= 0 ? a[i] - '0' : 0;
          int op_b = j >= 0 ? b[j] - '0' : 0;
          int sum = op_a + op_b + c;
          res  = char(sum%2+'0') + res;
          c = sum/2;
          i--;
          j--;
        }
        return res;
    }
};
int main(){


    string a = "1", b = "0";
    Solution solution;
    string result = solution.addBinary(a,b);
    cout << result << endl;
  

    
	return 0;
}