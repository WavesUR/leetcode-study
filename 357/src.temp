#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }

        int temp= 9;
        for(int i = 2; i <= n; i++){
            temp = temp*(9-i+2);
        }
        return countNumbersWithUniqueDigits(n-1) + temp;
    }
};

int main(){

int input = 1;
Solution solution;
int result = solution.countNumbersWithUniqueDigits(input);

cout << result << endl;
 
}