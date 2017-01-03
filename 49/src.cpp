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
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string> > result;
        if(len == 0){
          return result;
        }
        unordered_map<string, int> mymap;
        for(int i = 0; i < len; i++){
          string temp = strs[i];
          sort(temp.begin(),temp.end());
          auto got = mymap.find(temp);
          if(got == mymap.end()){
            mymap[temp] = i;
            result.push_back({strs[i]});
          }else{
            result[mymap[temp]].push_back(strs[i]);
          }
        }
        return result;
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