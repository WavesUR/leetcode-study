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
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.empty()){
        return "";
      }
        for(int i = 0; i < strs[0].length(); i++){
          for(int j = 1; j < strs.size();j++){
            if(strs[j][i] != strs[0][i]){
              return strs[0].substr(0,i);
            }
          }
        }
        return strs[0];
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