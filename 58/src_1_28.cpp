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
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = s.length() - 1; i >=0; i--){
            if(s[i] == ' '){
                if(len > 0){
                    return len;
                }
            }else{
                len++;               
            }
        }
        return len;
    }
};

int main(){


    string s = "a";
    int result;
	Solution solution;	
 
	result = solution.lengthOfLastWord(s);	
    cout << result << endl;


    
	return 0;
}