#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()){
//           return false;
//         }

//         int array[26] = {};


//         for(int i = 0; i < s.length();i++){
//           array[s[i]-'a']++;        
//         }

//         for(int i = 0; i < t.length();i++){
//           array[t[i]-'a']--;        
//         }

//         for(int i = 0; i < 26;i++){
//           if(array[i] != 0){
//             return false;
//           }
//         }

//         return true;
//       }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.length() != t.length()){
        //   return false;
        // }

        sort(s.begin(),s.end());
        sort(t.begin(), t.end());

        return s == t;
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