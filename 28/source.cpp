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
        int len_h = haystack.length();
        int len_n = needle.length();
        if(len_h < len_n){
          return -1;
        }
        int i = 0;
        while(i < len_h-len_n+1){
          int k = i;
          int j;
          for(j = 0; j < len_n;j++){
            if(needle[j] == haystack[k]){
              k++;
            }else{
              i++;
              break;
            }
          }
          if(j == len_n){
            return i;
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