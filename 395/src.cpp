#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int helper(string& s, int k, int start, int end){
        vector<int> map(26,0);
        for(int i = start; i < end; i++){
          map[s[i]-'a']++;
        }
        int max_len = 0;
        for(int i = start; i < end; ){
          while(map[s[i]-'a'] < k && i < end){
            i++;
          }
          if(i == end){
            break;
          }
          int j = i;
          while(map[s[j]-'a'] >= k && j < end){
            j++;
          }
          if(i == start && j == end){
            return end - start;
          }
          max_len = max(max_len,helper(s,k,i,j));
          i = j;
        }
        return max_len;
    }
    int longestSubstring(string s, int k) {
      return helper(s,k,0,s.length());
    }
};



int main(){

  string s = "ababbc";
  int k = 2;
  Solution solution;
  int res = solution.longestSubstring(s,k);
  cout << res << endl;



    
  return 0;
}