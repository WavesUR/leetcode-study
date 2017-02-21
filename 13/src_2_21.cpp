#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        map<char,int> map = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < s.length() - 1 && map[s[i]] < map[s[i+1]]){
                result = result - map[s[i]];
            }else{
                result = result + map[s[i]];
            }
        }
        return result;
    }
};

int main(){

string s = "MD";

Solution solution;
int result = solution.romanToInt(s);

cout << result << endl;

    
	return 0;
}