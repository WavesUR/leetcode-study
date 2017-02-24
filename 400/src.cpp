#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10){
            return n;
        }
        long base = 9;
        int i = 1;
        long mark = 9;
        while(n > mark){
            i++;
            n = n - mark;
            base = base * 10;
            mark = (base) * i;
        }
        long num = (n - 1) / i + pow(10,i - 1);
        int digit = (n - 1) % i;
        digit = i - digit;
        while((digit) > 1){
            num = num / 10;
            digit--;
        }
        return num%10;

    }
};
int main(){

    int num = 249;
    Solution solution;
    int res = solution.findNthDigit(num);
    cout << res << endl;

 
}