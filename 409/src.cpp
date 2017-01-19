#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;


// Time: O(n)
// Space: O(1)
class Solution {
public:
    int longestPalindrome(string s) {
//        unordered_map<char,int> my_map;
        vector<int> v(256);
        int len = s.length();
        int count = 0;
        for(int i = 0; i < len; i++){
            if(v[s[i]] == 0){
                v[s[i]] = 1;
            }else if(v[s[i]] == 1){
                count = count + 2;
                v[s[i]] = 0;
            }
        }

        return count < len ? count + 1 : count;
    }
};
int main(){

string str1 = "abccccdd";

Solution solution;
int result = solution.longestPalindrome(str1);
    // for(int i = 0; i < result.size();i++){
    //         cout << result[i]<< " ";
        
    // }
cout << result << endl;
    
	return 0;
}