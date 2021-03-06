#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
//        cout << n << endl;
        if(n == 1) return x;
        if(n == -1) return 1.0/x;
 //       if(n == INT_MIN) return 0;
 //       if(x == 0) return 0;       
        
        return myPow(x,n%2)*myPow(x*x,n/2);

    }
};


int main(){


    double x = 1;
    int n = INT_MIN;

    Solution solution;
    double result = solution.myPow(x,n);
    cout << result << endl;
    
  

    
	return 0;
}