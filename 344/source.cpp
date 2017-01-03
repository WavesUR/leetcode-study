#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    string reverseString(string s) {
        string::iterator iter, iter1;
//        string reversestr = s;
        for(iter = s.begin(), iter1 = s.end()-1; iter <= iter1; iter++,iter1--){
        	char temp = *iter1;
        	*iter1 = *iter;
        	*iter = temp;
        }
        return s;
    }
};

int main(){
	Solution solution;
	string str = "Hello!";
	string returnstr;
	returnstr = solution.reverseString(str);
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

