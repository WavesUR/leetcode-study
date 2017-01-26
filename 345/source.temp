#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    bool isvowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
      int j = s.length() - 1;
      int i = 0;
      while(i < j){
           while(!isvowels(s[i]))
           {
            i++;
           } 

           while(!isvowels(s[j]))
           {
            j--;
           } 
           if(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
           }
      } 
      return  s;
    }
};

int main(){
	Solution solution;
	string str = "Aa";
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

