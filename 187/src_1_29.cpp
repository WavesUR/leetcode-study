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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() < 11){
          return res;
        }
        unordered_map<string,bool> map;
        
        for(int i = 0; i <= s.length() - 10; i++){
          string t = s.substr(i,10);
          if(map.find(t) == map.end()){
            map[t] = true;
          }else if(map[t] == true){
            res.push_back(t);
            map[t] = false;
          }
        }
        return res;
    }
};

int main(){

  string s = "";
  Solution solution;
  vector<string> result = solution.findRepeatedDnaSequences(s);
  for(int i = 0; i< result.size();i++){
    cout << result[i] << endl;
  }
  //cout << result << endl;


    
  return 0;
}