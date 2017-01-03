#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
          x = - x;
          sign = 0;
        }
        long long result = 0;
        while(x > 0){
          result = result * 10 + x % 10;
          x = x / 10;
        }
        result =  sign == 1 ? result : -result;
        if(result > INT_MAX || result < INT_MIN){
          return 0;
        }
        return result;
    }
};

int main(){

  int x = 100;
  Solution solution;
  int result = solution.reverse(x);

  cout << result << endl;


    
  return 0;
}