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
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask1 = pow(2,31);
        uint32_t mask2 = 1;
        uint32_t res = 0;
        do{
          if(mask1 & n){
            res = res | mask2;
          }
          mask1 = mask1 >> 1;
          mask2 = mask2 << 1;
        }while(mask2 != 0);
        return res;
    }
};

int main(){

  uint32_t n = 43261596;
  Solution solution;
  uint32_t result = solution.reverseBits(n);
  cout << result << endl;


    
  return 0;
}