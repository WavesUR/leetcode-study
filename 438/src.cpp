#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
//#include <unordered_map>
using namespace std;


// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int s_len = s.length();
        int p_len = p.length();
        if( s_len < p_len){
            return v;
        }
        vector<int> count_p(26);
        vector<int> count_s(26);
        for(int i = 0; i < p_len; i++){
            count_p[p[i] - 'a']++;
            count_s[s[i] - 'a']++;
        }
        if(count_p == count_s){
            v.push_back(0);
        }
        for(int i = p_len; i < s_len; i++){
            count_s[s[i-p_len] - 'a']--;
            count_s[s[i] - 'a']++;
            if(count_p == count_s){
                v.push_back(i - p_len+1);
            }
        }
        return v;
    }
};

int main(){

string str1 = "";
string str2 = "a";

Solution solution;
vector<int> result = solution.findAnagrams(str1,str2);
    for(int i = 0; i < result.size();i++){
            cout << result[i]<< " ";
        
    }

    
	return 0;
}