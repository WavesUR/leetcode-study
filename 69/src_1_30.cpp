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
    int mySqrt(int x) {
        long left = 0, right = x, mid;
        while(left < right){
          mid = left + ((right - left + 1) >> 1);
          long temp = x/mid;
          if(mid > temp){
            right = mid - 1;
          }else {
            left = mid;
          }
        }
        return left;
    }
};

int main(){


    int num = 2147483647;
    Solution solution;
    int result = solution.mySqrt(num);
    cout << result << endl;
    
  

    
	return 0;
}