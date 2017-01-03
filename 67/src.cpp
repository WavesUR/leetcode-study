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

        int i_a = a.length() - 1;
        int i_b = b.length() - 1;
        string result="";
        while(i_a >= 0 || i_b >= 0 || c == 1){      
          int op_a = i_a >= 0 ? (a[i_a] - '0') : 0;
          int op_b = i_b >= 0 ? (b[i_b] - '0') : 0;
          int sum = op_a+op_b+c;
          result = char(sum%2 + '0')+result;
          c = sum/2;
          i_a--;
          i_b--;
        }
        return result;
    }
};

int main(){


    string a = "0", b = "0";
    Solution solution;
    string result = solution.addBinary(a,b);
    cout << result << endl;
  

    
	return 0;
}