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
    bool isPerfectSquare(int num) {
        int left = 1, right = num + 1, mid;
        while(left < right){
          mid = left + ((right-left) >> 1);
          if(mid < num/mid){
            left = mid + 1;
          }else if(mid > num/mid){
            right = mid;
          }else if(num%mid == 0){
            return true;
          }else{
            return false;
          }
        }
        return false;
    }
};

int main(){


    int num = 1;
    Solution solution;
    bool result = solution.isPerfectSquare(num);
    cout << result << endl;
    
  

    
	return 0;
}