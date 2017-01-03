#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int array1[256] = {0};
        int array2[256] = {0};
        for(int i = 0; i < s.length(); i++){
          if(array1[s[i]]!=array2[t[i]]){
            return false;
          }
          array1[s[i]] = i + 1;
          array2[t[i]] = i + 1;
        }
        return true;
    }
};


int main(){


    string s = "egg";
    string t = "adb";
//   cout << atoi(s.c_str()+1);
    Solution solution;
    bool result = solution.isIsomorphic(s,t);
    cout << result << endl;
    
  

    
	return 0;
}