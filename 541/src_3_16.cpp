#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    void rev(string& s, int i,int j){
        while(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k) {
        string res = s;
        int start = 0;
        while(start + k <= res.length()){
            rev(res,start,start+k-1);
            start = start + 2*k;
        }
        if(start < res.length()){
            rev(res,start,res.length() - 1);
        }
        return res;
    }
};

int main(){
	Solution solution;
	string str = "abcdefg";
    int k = 2;
	string returnstr;
	returnstr = solution.reverseStr(str,k);
	cout << returnstr << endl;
	return 0;
}