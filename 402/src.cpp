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
    string removeKdigits(string num, int k) {
        if(num.length() == k){
            return "0";
        }
        string res = "";
        int i = 0;
        while(i < num.size()){
            while(res.length() != 0 && k > 0 && num[i] < res.back()){
                k--;
                res.pop_back();
            }
            if(!(res.length() == 0 && num[i] == '0')){
                res = res + num[i];
            }          
            i++;
        }
        while(k > 0 && res.length() != 0){
            res.pop_back();
            k--;
        }
        return res == "" ? "0" : res;
    }
};


int main(){

string num = "1432219";
int k = 3;
Solution solution;
string result = solution.removeKdigits(num, k);
cout << result << endl;
    
return 0;
  
}