#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int mask = 1;
        int i = 0;
        int result = 0;
        while(i < 32){
          int bit_a = (mask & a) != 0 ? 1 : 0;
          int bit_b = (mask & b)  != 0 ? 1 : 0;
          result = result | ((bit_a ^ bit_b ^ c) != 0 ? mask : 0);
          c = (bit_a & bit_b) | (c & (bit_a ^ bit_b));
          i++;
          mask = mask << 1;
        }
        return result;
    }
};


int main(){

int a = 15;
int b = 25;
Solution solution;
int result = solution.getSum(a,b);
cout << result << endl;

    
return 0;
}