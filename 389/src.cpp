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
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size(); i++){
            res = s[i] ^ res;
        }
        for(int i = 0; i < t.size(); i++){
            res = t[i] ^ res;
        }
        return res;
    }
};

int main(){


	Solution solution;	
    string s = "abcd";
    string t = "abecd";
    char result = solution.findTheDifference(s,t);      
    cout << result;
    cout << endl;

    
	return 0;
}