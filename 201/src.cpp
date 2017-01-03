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
        if(m == 0){
          return 0;
        }
        int mask = 1;
        while(m != n){
          m >>= 1;
          n >>= 1;
          mask <<= 1;
        }
        cout << m << mask << endl;
        return m*mask;
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