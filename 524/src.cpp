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
    string findLongestWord(string s, vector<string>& d) {
        string res;
        int d_size = d.size();
        if(d_size == 0){
            return "";
        }
        int s_size = s.size();
        vector<pair<int,int> > lens(d_size);
        for(int i = 0; i < d_size; i++){
            lens[i] = make_pair(d[i].length(),i);
        }

        sort(lens.begin(),lens.end(),[&d](pair<int,int>& a, pair<int,int>& b){ 
            if(a.first > b.first){
                return true;
            }else if(a.first < b.first){
                return false;
            }else{
                return lexicographical_compare(d[a.second].begin(),d[a.second].end(),d[b.second].begin(),d[b.second].end());
            }
        });

        for(int i = 0; i < d_size; i++){
            if(lens[i].first > s_size){
                continue;
            }
            int slow = 0;
            int fast = 0;
            while(fast < s_size && slow < lens[i].first){
                if(s[fast] == d[lens[i].second][slow]){
                    fast++;
                    slow++;
                }else{
                    fast++;
                }
            }
            if(slow == lens[i].first){
                return d[lens[i].second];
            }
        }
        return "";
    }
};

int main(){

    vector<string> words = {"zxc","vbn"};
    string s = "apple";
    Solution solution;
    string res = solution.findLongestWord(s, words);
    cout << res << endl;

 
}