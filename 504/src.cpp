#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    string convertToBase7(int num) {
        int x = abs(num);
        string res;
        do{
            res = char(x%7 + '0') + res;
            x = x / 7;
        }while(x);
        return num >=0 ?  res : "-"+res;
    }
};
int main(){

    int num = -7;
    Solution solution;
    string res = solution.convertToBase7(num);
    cout << res << endl;

 
}