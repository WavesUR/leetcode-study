#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
    int addDigits(int num) {
        return num - 9*((num-1)/9);
    }
};

int main(){
	Solution solution;
	int num = 2035;
    int returnnum;
	returnnum = solution.addDigits(num);
    cout << returnnum << endl;
	return 0;
}