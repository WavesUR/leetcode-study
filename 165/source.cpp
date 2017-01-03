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
        int loc1 = version1.find('.');
        int loc2 = version2.find('.');
        if(atoi(version1.substr(0,loc1).c_str())>atoi(version2.substr(0,loc2).c_str())){
            return 1;
        }else if(atoi(version1.substr(0,loc1).c_str())<atoi(version2.substr(0,loc2).c_str())){
            return -1;
        }else{
            if(loc1 == -1 && loc2 == -1){
               return 0; 
            }else{
                return compareVersion(loc1 == -1 ? "0" : version1.substr(loc1+1),loc2 == -1 ? "0" : version2.substr(loc2+1));
            }
        }
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