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
    void dfs(string& s, unordered_map<string,bool>& map, vector<string>& res, string& t, int start, int end, vector<bool>& memo){
      if(memo[start] == false){
        return;
      }
      if(start >= s.length() && end >= s.length()){
        t.pop_back();
        res.push_back(t);
        return;
      }else if(end >= s.length()){
        return;
      }


      for(int i = end; i < s.length(); i++){
        string str = s.substr(start,i - start + 1);        
        if(map[str]){
          string temp = t + str + " ";
          dfs(s,map,res,temp,i+1,i+1,memo);
        }
      }
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_map<string,bool> my_map;
        for(int i = 0; i < len;i++){
          my_map[wordDict[i]] = true;
        }
        vector<bool> memo(len+1,false);
        memo[len] = true;
        for(int i = len; i >= 0; i--){
          for(int j = i - 1; j >= 0; j--){
            if(memo[i]){
             if(my_map.find(s.substr(j,i-j)) != my_map.end()){
              memo[j] = true;
            }             
            }

          }
        }
        cout << memo[0] << endl;
        vector<string> res;
        string t;
 //       dfs(s, my_map, res, t,0,0,memo);
        return res;
    }
};

int main(){

  vector<string> wordDict;
  wordDict = {"cat","cats","and","sand","dog"};
  string s = "catsanddog";
  Solution solution;
  vector<string> result = solution.wordBreak(s,wordDict);
  for(auto str : result){
    cout << str << endl;
  }
  //cout << result << endl;

    
  return 0;
}