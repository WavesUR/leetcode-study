#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int p_len = pattern.length();
        int s_len = str.length();
        if(p_len == 0 || s_len == 0){
          return false;
        }
        unordered_map<string,int> mymap1;
        unordered_map<char,int> mymap;
        int start = 0, last = 0;

        for(int i = 0; i<p_len;i++){
            while(str[last] != ' ' && last < s_len){
              last++;
            }
            if(last == start){
              return false;
            }
            string temp = str.substr(start,last-start);
            if(mymap[pattern[i]] != mymap1[temp]){
              return false;
            }
            mymap[pattern[i]] = i + 1;
            mymap1[temp] = i + 1;

            start = last + 1;
            last = last + 1;
        }

        return last-1 == s_len ? true : false ;

    }
};


int main(){


    string p = "aaa";
    string s = "dog dog dog dog";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    bool result = solution.wordPattern(p,s);
    cout << result << endl;
    
  

    
	return 0;
}