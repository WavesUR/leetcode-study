#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <utility> 
using namespace std;

// Time: O(n + 26log26)
// Space: O(n + 26)
class Solution {
public:
    string reorganizeString(string S) {
        int n = S.length();
        vector<int> cnt = vector<int>(26,0);
        for(int i = 0; i < n; i++){
          cnt[S[i] - 'a'] += 100;
        }
        for(int i = 0; i < 26; i++){
          cnt[i] += i;
        }
        sort(cnt.begin(), cnt.end());

        string T(n,' ');
        int t = 1;
        for(int i = 0; i < 26; i++){
          int ct = cnt[i] / 100;
          if(ct > (n+1)/2){
            return "";
          }
          char ch = (char)('a' + cnt[i] % 100);
          for(int j = 0; j < ct; j++){
            if(t >= n){
              t = 0;
            }
            T[t] = ch;
            t += 2;
          }
        }
        return T;

    }
};



int main(){
  string str;
  str = "vvvlo";
  Solution solution;
  string result = solution.reorganizeString(str);
  cout << result << endl;


    
  return 0;
}