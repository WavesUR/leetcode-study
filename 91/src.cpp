#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Time: O()
// Space: O()
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s[0] == '0') return 0;
        vector<int> memo(len+ 1,0);
        memo[len] = 1;
        memo[len - 1] = s[len - 1] == '0' ? 0 : 1; 

        for(int i = s.length() - 2; i >= 0; i--){
            if(s[i] == '0'){
                continue;
            }
            if(((s[i] == '2' && (s[i+1] - '6' <= 0)) || s[i] == '1')  ){
                    memo[i] = memo[i  + 1] + memo[i + 2];
               
            }else{
                memo[i] = memo[i+1];                
            }
        }
        return memo[0];
    }
};

int main(){

    string s = "12120";
    string result;
    Solution solution;
    int res = solution.numDecodings(s);
    cout << res << endl; 


    
	return 0;
}