#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string t = s;
        int i = 0, j = 0;
        for( ; i < t.length(); i++){
            if(t[i] == ' ' || i == t.length() - 1){
                int temp = i;
                if(t[i] == ' '){
                    i--;
                }
                while(j < i){
                    swap(t[i],t[j]);
                    j++;
                    i--;
                }
                i = temp + 1;
                j = temp + 1;
            }
        }
        return t;
    }
};

int main(){
	Solution solution;
	string str = "Let's take LeetCode contest";
	string returnstr;
	returnstr = solution.reverseWords(str);
    cout << str << endl;
	cout << returnstr << endl;
	return 0;
}