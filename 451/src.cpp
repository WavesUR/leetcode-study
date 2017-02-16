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
    string frequencySort(string s) {
        int len = s.length();
        if(len < 3){
          return s;
        }
        vector<int> map(26,0);
        for(int i = 0; i < len; i++){
          map[s[i]-'a']++;
        }
        
    }
};

int main(){

string s = "tree";

Solution solution;
string result = solution.frequencySort(s);

cout << result << endl;

    
    return 0;
}