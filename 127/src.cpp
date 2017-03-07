#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findneighbors(string s, unordered_set<string>& wordset){
      vector<string> res;
      for(int i = 0; i < s.length(); i++){
        char c = s[i];
        for(int j =0; j < 26; j++){
          if(c == 'a' + j){
            continue;
          }
          s[i] = 'a' + j;
          if(wordset.find(s) != wordset.end()){
            res.push_back(s);
            wordset.erase(s);
          }
        }
        s[i] = c;
      }
      return res;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if(wordset.find(endWord) == wordset.end()){
          return 0;
        }
        // wordset.insert(endWord);
        queue<pair<string, int> > q;
        q.push(make_pair(beginWord,1));
        while(!q.empty()){
          auto temp = q.front();
          string s = temp.first;
          int level = temp.second;
          if(s == endWord){
            return level;
          }
          q.pop();
          vector<string> neighbors = findneighbors(s,wordset);
          for(int i = 0; i < neighbors.size(); i++){
            q.push(make_pair(neighbors[i],level+1));
          }
        }
        return 0;
    }
};

int main(){

  vector<string> nums = {"hot","dot","dog","lot","log","cog"};
  Solution solution;
  int result = solution.ladderLength("hit","cog",nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}