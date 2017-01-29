#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Time ？
class Solution {
public:
    string gen(string input){
        int count = 0;
        int slow = 0;
        int fast = 1;
        string res;
        while(fast < input.length()){
            if(input[slow] != input[fast]){
                res= res + (to_string(fast - slow)+input[slow]);
                slow = fast;
                fast++;
            }else{
                fast++;
            }
        }
        res= res + (to_string(fast - slow)+input[slow]);
        return res;
    }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        return gen(countAndSay(n-1));

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