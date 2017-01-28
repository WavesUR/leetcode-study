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
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end){
          while(!isalnum(s[start]) && start < end){
            start++;
          }
          while(!isalnum(s[end]) && start < end){
            end--;
          }
          if(tolower(s[start]) == tolower(s[end])){
            start++;
            end--;
          }else{
             return false;
          }
        }
        return true;
    }
};

int main(){


    string str1 = "0P";
    Solution solution;
    bool result = solution.isPalindrome(str1);
    cout << result << endl;


    
	return 0;
}