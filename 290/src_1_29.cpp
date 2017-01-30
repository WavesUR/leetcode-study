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
        int start = 0;
        int end = 0;
        vector<string> v;
        while(end < str.length()){
            if(str[end] != ' '){
                end++;
            }else{
                v.push_back(str.substr(start, end-start));
                end++;
                start = end;
            }
        }
        v.push_back(str.substr(start, end-start));
        if(v.size() != pattern.length()){
            return false;
        }
        unordered_map<char, int> map1;
        unordered_map<string, int> map2;
        for(int i = 0; i < pattern.length(); i++){
            if(map1[pattern[i]] != map2[v[i]]){
                return false;
            }                
            map1[pattern[i]] = i + 1;
            map2[v[i]] = i + 1;
        }
        return true;
    }
};

int main(){


    string p = "abba";
    string s = "dog dog dog dog";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    bool result = solution.wordPattern(p,s);
    cout << result << endl;
    
  

    
	return 0;
}