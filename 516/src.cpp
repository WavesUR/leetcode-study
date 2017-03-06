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
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > memo(s.length(),vector<int>(s.length(),0));
        for(int len = 1; len <= s.length(); len++){
            for(int i = 0; i + len <= s.length(); i++){
                int j = i + len - 1;
                if(i == j){
                    memo[i][j] == 1;
                }else if(i == j - 1){
                    memo[i][j] == (s[i] == s[i]) ? 2 : 1;
                }else{
                    int add = (s[i] == s[j]) ? 2 : 0;
                    memo[i][j] = max(max(memo[i+1][j],memo[i][j-1]),memo[i+1][j-1] + add);

                }
            }
        }
        return memo[0].back();

    }
};
int main(){

    string s = "hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr";
    int result;
    Solution solution;
    result = solution.longestPalindromeSubseq(s);
    cout << result << endl; 


    
	return 0;
}