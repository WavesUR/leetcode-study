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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        if(strs.empty()){
          return res;
        }
        int cur = 0;
        unordered_map<string, int> my_map;
        for(int i = 0; i < strs.size(); i++){
          string temp = strs[i];
          sort(temp.begin(),temp.end());
          if(my_map.find(temp) == my_map.end()){
            my_map[temp] = cur;
            res.push_back({strs[i]});
            cur++;
          }else{
            res[my_map[temp]].push_back(strs[i]);
          }
        }
        return res;
    }
};

int main(){

  vector<string> strs;
  strs = {"eat", "tea"};
  Solution solution;
  vector<vector<string> > result = solution.groupAnagrams(strs);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}