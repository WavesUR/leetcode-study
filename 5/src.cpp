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
    string longestPalindrome(string s) {
        if(s == ""){
            return "";
        }
        string max_str;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i+1]){
                int j = i - 1;
                int k = i + 2;
                int count = 2;
                while(j >=0 && k < s.length() && s[j] == s[k]){
                        count = count + 2;
                        j--;
                        k++;
                    }
                max_str = count > max_str.length() ? s.substr(j+1, k - j - 1) : max_str;              
                }
            }
        for(int i = 1; i < s.length() - 1; i++){
            if(s[i-1] == s[i+1]){
                int j = i - 2;
                int k = i + 2;
                int count = 3;
                while(j >=0 && k < s.length() && s[j] == s[k]){
                        count = count + 2;
                        j--;
                        k++;
                    }
                max_str = count > max_str.length() ? s.substr(j+1, k - j - 1) : max_str;              
                }
            }

        return max_str == "" ? s.substr(0,1) : max_str;
    }
};

int main(){

    string s = "c";
    string result;
    Solution solution;
    result = solution.longestPalindrome(s);
    cout << result << endl; 


    
	return 0;
}