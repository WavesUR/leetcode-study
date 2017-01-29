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
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};

int main(){

    string s = "the sky is blue";
    string result;
    Solution solution;
    solution.reverseWords(s);
    cout << s << endl; 


    
	return 0;
}