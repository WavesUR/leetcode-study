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
    int finddep(string s, int i){
        if(i == s.size()-1){
            return 1;
        }else if(s[i] == s[i+1]){
            return 1+finddep(s,i+1);
        }else{
            return 1;
        }

    }

    string countAndSayinter(string s){
         string result;
         int i = 0;
         while(i<s.size()){
            int j = finddep(s,i);
            result.push_back('0'+j);
            result.push_back(s[i]);
            i = i + j;
         }
         return result;
    }

    string countAndSay(int n) {
        string s = "1";
        for(int i = 0; i<n-1; i++){
            s = countAndSayinter(s);
        }
    return s;
    }
};

int main(){

    int n = 5;
    string result;
    Solution solution;
    result = solution.countAndSay(n);
    cout << result << endl; 


    
	return 0;
}