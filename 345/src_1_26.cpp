#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    bool isvowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i<j){
          if(isvowels(s[i]) && isvowels(s[j])){
            swap(s[i],s[j]);
          }else if(isvowels(s[i])){
            j--;
            continue;
          }else if(isvowels(s[j])){
            i++;
            continue;
          }
          i++;
          j--;
        }
        return s;
    }
};

int main(){
	Solution solution;
	string str = "Hello";
	string returnstr;
	returnstr = solution.reverseVowels(str);
	cout << returnstr << endl;
	return 0;
}

// class Solution {
// public:
//     string reverseString(string s) {
//         size_t len = s.size();
//         string reversestr = s;
//         for(size_t i = 0; i < len; i++){
//         	reversestr[i] = s[len-i-1];
//         }
//         return reversestr;
//     }
// };

