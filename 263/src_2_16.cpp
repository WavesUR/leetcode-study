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
    bool isUgly(int num) {
        if(num <= 0){
            return false;
        }
        while(num%2 == 0){
            num = num >> 1;
        }
        while(num%3 == 0){
            num = num / 3;
        }
        while(num%5 == 0){
            num = num / 5;
        }

        return num == 1 ? true : false;
    }
};

int main(){

int n = 60;

Solution solution;
int result = solution.isUgly(n);

cout << result << endl;

    
	return 0;
}