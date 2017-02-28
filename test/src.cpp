#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if(len == 1){
            return true;
        }
        if(isupper(word[0])){
            auto check = isupper(word[1]);
            int i = 2;
            while(i < len){
                if(isupper(word[i]) != check){
                    return false;
                }
                i++;
            }
        }else{
            auto check = isupper(word[0]);
            int i = 1;
            while(i < len){
                if(isupper(word[i]) != check){
                    return false;
                }
                i++;
            }           
        }
        return true;
    }
};
int main(){

    string word = "gooGle";
    Solution solution;
    bool res = solution.detectCapitalUse(word);
    int i = 4;
    cout << (i & (-i)) << endl;

 
}