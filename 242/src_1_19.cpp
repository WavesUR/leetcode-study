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


// Time: O(nlogn)
// Space: O(1)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//     	if(s.size() != t.size()){
//     		return false;
//     	}
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         return s == t;
//     }
// };

// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size()){
    		return false;
    	}
        
        int count[26] = {};
        for(int i = 0; i < s.size(); i++){
        	count[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
        	count[t[i] - 'a']--;
        	if(count[t[i] - 'a'] < 0){
        		return false;
        	}
        }
        return true;
    }
};
int main(){

string str1 = "ab";
string str2 = "ba";

Solution solution;
bool result = solution.isAnagram(str1,str2);

cout << result << endl;

    
	return 0;
}