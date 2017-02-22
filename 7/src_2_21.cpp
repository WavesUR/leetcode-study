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
        long res = 0;
        while(x != 0){
          int bit = x % 10;
          cout << bit << endl;
          res = res * 10 + bit;
          x = x / 10;
        }
        if(res > INT_MAX || res <INT_MIN){
          return 0;
        }else{
          return (int)res;
        }
        
    }
};

int main(){

  int x = -10;
  Solution solution;
  int result = solution.reverse(x);

  cout << result << endl;


    
  return 0;
}