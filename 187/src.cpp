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
        vector<string> result;
        if(s.length() < 11){
          return result;
        }
        unordered_map<string,int> my_map;
        for(int i = 0; i <= s.length() - 10; i++){
          string ssub = s.substr(i,10);
          auto found = my_map.find(ssub);
          if(found == end(my_map)){
            my_map[ssub] = 1;
          }else if(my_map[ssub] == 1){
            result.push_back(ssub);
            my_map[ssub]++;
          }
        }
        return result;
    }
};

int main(){

  string s = "AAAAAAAAAAAA";
  Solution solution;
  vector<string> result = solution.findRepeatedDnaSequences(s);
  for(int i = 0; i< result.size();i++){
    cout << result[i] << endl;
  }
  //cout << result << endl;


    
  return 0;
}