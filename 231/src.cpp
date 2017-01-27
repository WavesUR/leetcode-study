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
    bool isPowerOfTwo(int n) {
         return n > 0 && !(n&(n-1));
    }
};

int main(){

  int n = 4;
  Solution solution;
  bool result = solution.isPowerOfTwo(n);
  cout << result << endl;


    
  return 0;
}