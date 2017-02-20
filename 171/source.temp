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
        int len = s.length();
        int result = 0;
        for(int i = 0; i < len; i++){         
           result = result + (s[i]-'A'+1)*pow(26.0,len-i-1);
        }
        return result;
    }
};

int main(){

	


    string str = "AA";
    int result;
	Solution solution;	
 
	result = solution.titleToNumber(str);	

    cout << result <<endl;

//	cout << result << endl;

    
	return 0;
}