#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
       vector<int> map(26,0);
       for(int i = 0; i < s.length(); i++){
          map[s[i] - 'a']++;
       } 
       for(int i = 0; i < s.length(); i++){
          if(map[s[i] - 'a'] == 1){
            return i;
          }
       }
       return -1;
    }
};

int main(){


    string s = "loveleetcode";
    Solution solution;
    int result = solution.firstUniqChar(s);
    cout << result << endl;


    
	return 0;
}