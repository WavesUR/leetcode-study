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
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 10;
        }
        vector<int> memo(n+1,0);   
        memo[0] = 1;     
        int sum = 0;               
        for(int i = 1; i <=n ;i++){
            memo[i] = memo[i-1] * (9 - i + 2);
            sum = sum + memo[i];
        }
        return sum; 
    }
};

int main(){

int input = 2;
Solution solution;
int result = solution.countNumbersWithUniqueDigits(input);

cout << result << endl;
 
}