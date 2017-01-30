#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map_s(256,0);
        vector<int> map_t(256,0);
        for(int i = 0; i < s.length(); i++){
          if(map_s[s[i]] != map_t[t[i]]){
            return false;
          }
          map_s[s[i]] = i + 1;
          map_t[t[i]] = i + 1;
        }
        return true;
    }
};


int main(){


    string s = "ab";
    string t = "aa";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    bool result = solution.isIsomorphic(s,t);
    cout << result << endl;
    
  

    
	return 0;
}