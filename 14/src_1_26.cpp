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
        int len = strs.size();
        if(len == 0){
          return "";
        }
        int k = strs[0].size();
        for(int i = 1; i < len; i++){
          int j = strs[i+1].size();
          if(k > j){
            k = j;
          }
          while(k >= 0){
            if(strs[i][k] == strs[0][k]){
              break;
            }
            k--;
          }
          if(k < 0){
            return "";
          }          
        }
        return strs[0].substr(0,k);
    }
};

int main(){


    vector<string> v = {"aasabeed","ab"};
    Solution solution;
    string result = solution.longestCommonPrefix(v);
    cout << result << endl;


    
	return 0;
}