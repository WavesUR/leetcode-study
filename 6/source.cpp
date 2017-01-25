#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len < 3 || numRows <= 1 || len < numRows){
          return s;
        }
        int cur = 0;

        string t;
        int zigSpan = numRows*2 - 2; 
        for(int i = 0; i < numRows; i++){
          for(int j = i; j < len; j+=zigSpan){
            t.push_back(s[j]);
            if(i != 0 && i != numRows - 1 && j + zigSpan - 2*i < len){
              t.push_back(s[j + zigSpan - 2*i]);
            }
          }
        }

        return t;
    }
};


int main(){
int n = 3;
Solution solution;
string s = "PAYPALISHIRING";
string result = solution.convert(s,n);
cout << result << endl;


    
return 0;
}