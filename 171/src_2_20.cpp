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
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            sum = sum * 26 + (s[i] - 'A' + 1);
        }
        return sum;
    }
};

int main(){

	


    string str = "Z";
    int result;
	Solution solution;	
 
	result = solution.titleToNumber(str);	

    cout << result <<endl;


    
	return 0;
}