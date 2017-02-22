#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Time: O()
// Space: O()
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        int slow = 0;
        int fast = 1;
        while(fast < len){
            while(fast < len && !(s[fast] == ' ' && s[fast-1] != ' ')){
                fast++;
            }
            int fast_temp = fast - 1;
            int slow_temp = slow;
            while(slow_temp < fast_temp){
                swap(s[slow_temp],s[fast_temp]);
                slow_temp++;
                fast_temp--;
            }
            while(slow < len && !(s[slow] == ' ' && s[slow-1] != ' ')){
                slow++;
            }
             slow = slow + 1;
             fast = fast + 1;
        }
        while(s[len-1] == ' '){
            len--;
        }
        s = s.substr(0,len);
        reverse(s.begin(),s.end());
    }
};

int main(){

    string s = " ";
    cout << s << "." <<endl;
    string result;
    Solution solution;
    solution.reverseWords(s);
    cout << s << "." <<endl; 


    
	return 0;
}