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
    int hammingWeight(uint32_t n) {
        int result = 0;
        int i = 0;
        int a = 1;
        while(i<32){
            if(n & a == 1){
                result++;
            }
            n = n >> 1;
            i++;
        }
        return result;
    }
};

int main(){

    uint32_t n = 10;
    int result;
	Solution solution;	
 
	result = solution.hammingWeight(n);	

    cout << result << endl;


    
	return 0;
}