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
    bool repeatedSubstringPattern(string str) {
    	int len = str.length();
        for(int i = 1; i < len/2; i++){
        	if(str[i] == str[0] && len%i == 0){
        		int cur = i;
        		while( cur < str.length()){
        			if(str.substr(0,i) != str.substr(cur,i)){
        				break;
        			}
        			cur = cur + i;
        		}
        		if(cur == str.length()){
        			return true;
        		}

        	}
        }
        return false;
    }
};

int main(){

  string s = "aba";
  Solution solution;
  bool result = solution.repeatedSubstringPattern(s);


  cout << result << endl;

  return 0;
}