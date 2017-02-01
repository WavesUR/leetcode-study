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
    int arrangeCoins(int n) {
        long left = 0, right = n, mid;
        while(left < right){
          mid = left + ((right - left) / 2) + 1;
          long temp = mid*(mid+1)/2;
          if(temp <= n){
            left = mid;
          }else{
            right = mid - 1;
          }
        }
        return left;
    }
};

int main(){


    int num = 1804289383;
    Solution solution;
    int result = solution.arrangeCoins(num);
    cout << result << endl;
    
  

    
	return 0;
}