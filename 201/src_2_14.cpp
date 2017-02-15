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
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1;
        while(m != n){
          m = m & ~mask;
          n = n & ~mask;
          mask = mask << 1;
        }
        return m;
    }
};

int main(){

  int m = 5;
  int n = 7;
  Solution solution;
  int result = solution.rangeBitwiseAnd(m, n);
  cout << result << endl;


    
  return 0;
}