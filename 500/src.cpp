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
    vector<string> findWords(vector<string>& words) {
        map<char,int> Map = {{'Q',1},{'W',1},{'E',1},{'R',1},{'T',1},{'Y',1},{'U',1},{'I',1},{'O',1},{'P',1},
        {'A',2},{'S',2},{'D',2},{'F',2},{'G',2},{'H',2},{'J',2},{'K',2},{'L',2},
         {'Z',3},{'X',3},{'C',3},{'V',3},{'B',3},{'N',3},{'M',3} };
         vector<string> res;
        for(int i = 0; i < words.size(); i++){
            int level = Map[toupper(words[i][0])];
            int j = 1;
            for(j = 1; j < words[i].length(); j++){
                if(Map[words[i][j]] != level && Map[toupper(words[i][j])] != level){
                    break;
                }
            }
            if(j == words[i].length()){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

int main(){

    vector<string> words = {"abdfs","cccd","a","qwwewm"};
    Solution solution;
    vector<string> res = solution.findWords(words);
    for(auto r : res){
        cout << r << endl;
    }

 
}