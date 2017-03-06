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
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int num1 = 0;
        int num2 = 0;
        while(i < version1.size() || j < version2.size()){
            while(version1[i] != '.' && i < version1.size() ){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            while(version2[j] != '.' && j < version2.size()){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;               
            }
            j++;
            cout << num1 << " " << num2 << endl;
            if(num1 > num2){
                return 1;
            }else if(num1 < num2){
                return -1;
            }
            num1 = 0;
            num2 = 0;
        }
        return 0;
             
    }
};

int main(){


    string str1 = "1.12";
    string str2 = "1.12.0";
    Solution solution;
    int result = solution.compareVersion(str1,str2);
 string myString = "45";
int value = atoi(myString.c_str()); 
    cout << result << endl;


    
	return 0;
}