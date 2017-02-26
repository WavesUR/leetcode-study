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
        int i = 1;
        while(x / i >= 10){
          i = i * 10;
        }
        int j = 10;
        while(x > 0){
          int upper = x / i;
          int lower = x % j;
          if(upper != lower){
            return false;
          }
          x = x % i;
          x = x / 10;
          i = i / 100;
        };
   
    return true;
     }
};

int main(){

  int x = 12321;
  Solution solution;
  bool result = solution.isPalindrome(x);

  cout << result << endl;


    
  return 0;
}