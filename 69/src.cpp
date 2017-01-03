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
      int result;
        if(x < 0){
          return result;
        }

      int l = 1, r = x;
      int c;
      while(l < r){
        c = l+(r-l+1)/2;
        int y = x/c;
        if(c < y){
          l = c;
        }else if(c > y){
          r = c - 1;
        }else{
            return c;
        }
      }

      return l;
    }
};

int main(){


    int num = 5;
    Solution solution;
    int result = solution.mySqrt(num);
    cout << result << endl;
    
  

    
	return 0;
}