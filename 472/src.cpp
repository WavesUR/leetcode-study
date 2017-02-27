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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool> map;
        for(int i = 0; i < words.size(); i++){
          
        }
    }
};
int main(){

  vector<string> wordDict;
  wordDict = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
  Solution solution;
  vector<string> result = solution.findAllConcatenatedWordsInADict(wordDict);
  for(auto str : result){
    cout << str << endl;
  }
  //cout << result << endl;

    
  return 0;
}