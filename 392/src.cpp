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
    bool isSubsequence(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        int cur1 = 0;
        int cur2 = 0;
        while(cur1 < s_len && cur2 < t_len){
          if(s[cur1] == t[cur2]){
            cur1++;
            cur2++;
          }else{
            cur2++;
          }
        }
        return cur1 == s_len;
    }
};

int main(){
  string s = "abs";
  string t = "ahbgds";
  Solution solution;
  bool result = solution.isSubsequence(s,t);
  cout << result << endl;


    
  return 0;
}