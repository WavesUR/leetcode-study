#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>
using namespace std;


class Solution {
public:
    bool isPowerOfFour(int num) {
        return (!(num & (num-1)) && (0x55555555 & num));
    }
};

int main(){

int n = 16;

Solution solution;
bool result = solution.isPowerOfFour(n);
cout << result << endl;

    
	return 0;
}