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
        int count = 0;
        while(n != 0){
            count++;
            n = n & (n - 1);
        }
    
    return count;
}
};

int main(){

    uint32_t n = 11;
    int result;
	Solution solution;	
 
	result = solution.hammingWeight(n);	

    cout << result << endl;


    
	return 0;
}