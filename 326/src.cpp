#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0){
            return false;
        }
        while(n % 3 == 0){
            n = n / 3;
        }
        return n == 1;
    }
};

int main(){

int n = 18;

Solution solution;
bool result = solution.isPowerOfThree(n);

cout << result << endl;

    
    return 0;
}