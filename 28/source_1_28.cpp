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
    int strStr(string haystack, string needle) {
        int n_len = needle.length();
        int h_len = haystack.length();
        if(n_len == 0){
          return 0;
        }

        int i = 0;
        while(i <= h_len - n_len){
          if(haystack[i] != needle[0]){
            i++;
            continue;
          }
          if(haystack.substr(i,n_len) == needle){
            return i;
          }else{
            i++;
          }
        }
        return -1;

    }
};

int main(){


    string haystack = "aasabeed";
    string needle = "ab";
    Solution solution;
    int result = solution.strStr(haystack, needle);
    cout << result << endl;


    
	return 0;
}