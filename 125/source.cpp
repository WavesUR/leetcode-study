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
        int i = 0, j = s.length()-1;
        while(i < j){
          while(!isalnum(s[i]) && i < j){
            i++;
          }
          while(!isalnum(s[j]) && i < j){
            j--;
          }
          if(tolower(s[i]) == tolower(s[j])){
            i++;
            j--;
          }else{
            return false;
          }
        }
        return true;
    }
};

int main(){


    string str1 = "  ";
    Solution solution;
    bool result = solution.isPalindrome(str1);
    cout << result << endl;


    
	return 0;
}