#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_map<string,bool> my_map;
        for(int i = 0; i < wordDict.size();i++){
          my_map[wordDict[i]] = true;
        }
        vector<bool> memo(len+1,false);
        memo[0] = true;
        for(int i = 1; i <= len; i++){
          for(int j = i - 1; j >= 0; j--){
            if(memo[j] && my_map.find(s.substr(j,i-j)) != my_map.end()){
              memo[i] = true;
              break;
            }
          }
        }
        return memo[len];
    }
};
int main(){

  vector<string> wordDict;
  wordDict = {"leet", "code"};
  string s = "leetcode";
  Solution solution;
  bool result = solution.wordBreak(s,wordDict);
  cout << result << endl;


    
  return 0;
}