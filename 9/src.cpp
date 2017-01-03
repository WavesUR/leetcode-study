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
    bool isPalindrome(int x) {
        if(x < 0){
          return false;
        }
        int d = 1;
        while(x / d >= 10){
          d = d * 10;
        }

        while(x > 0){
          int high_bit = x / d;
          int low_bit = x % 10;      
          if(high_bit != low_bit){
            return false;
          }
          x = x % d;
          x = x / 10;
          d = d / 100;
        }
        return true;
    }
};

int main(){

  int x = 12351;
  Solution solution;
  bool result = solution.isPalindrome(x);

  cout << result << endl;


    
  return 0;
}