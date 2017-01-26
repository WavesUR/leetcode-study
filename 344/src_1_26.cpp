#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    string reverseString(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            swap(s[start],s[end]);
            start++;
            end--;
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