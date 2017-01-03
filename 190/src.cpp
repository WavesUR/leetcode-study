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
        uint32_t mask = 1;
        uint32_t result = 1;
        int i = 0;
        while(i < 32){
        if((int)(n & mask) != 0){
          result = (result << 1) | 1; 
          cout <<result << endl;
        }else{
          result = result << 1; 
        }

        mask = mask << 1;
        i++;      
        }
        return result;
    }
};

int main(){

  uint32_t n = 43261596;
  Solution solution;
  uint32_t result = solution.reverseBits(n);
  cout << result << endl;


    
  return 0;
}