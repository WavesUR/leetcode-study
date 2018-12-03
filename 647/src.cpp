#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int dp(string& str, vector<vector<int> >& memo, int s, int e){
        if(s > e){
            return 0;
        }
        if(memo[s][e] != -1){
            return memo[s][e];
        }
        if(s == e){
            return memo[s][e] = 1;       
        }
        if(str[s] == str[e]){
            if(s + 1 == e){
                return 1;
            }
            return memo[s][e] = dp(str, memo, s+1, e-1);
        }
        return memo[s][e] = 0;
    }
    int countSubstrings(string s) {
        if(s == ""){
            return 0;
        }
        int n = s.length();
        vector<vector<int> > memo(n, vector<int>(n,-1));
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                sum += dp(s, memo, i, j);
                cout << dp(s, memo, i, j) << " ";
            }
            cout << endl;
        }
        return sum;
    }
};

int main(){

    string s = "aaa";
    int result;
    Solution solution;
    result = solution.countSubstrings(s);
    cout << result << endl; 


    
	return 0;
}