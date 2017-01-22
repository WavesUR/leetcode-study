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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> my_map;
        int max_counter = 0;
        int start = 0;
        int i;
        for(i = 0; i < s.length(); i++){
          if(my_map.find(s[i]) == my_map.end() || my_map[s[i]] < start){
            my_map[s[i]] = i; 
          }else{
            max_counter = max(max_counter,i - start);
            start = max(my_map[s[i]],start) + 1;
            my_map[s[i]] = i; 
          }
        }
        return max(max_counter, i - start);
    }
};

int main(){

  string s = "tmmzuxt";
  Solution solution;
  int result = solution.lengthOfLongestSubstring(s);

  cout << result << endl;


    
  return 0;
}