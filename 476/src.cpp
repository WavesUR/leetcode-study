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
    int findComplement(int num) {
        int res = 0;
        int mask = 1;
        while(num){       
          if(!(num & 1)){
            res = res | mask;
          }
          num = num >> 1;
          mask = mask << 1;
          cout << num << " " << res << endl;
        }
        return res;
    }
};

int main(){

  int m = 5;
  Solution solution;
  int result = solution.findComplement(m);
  cout << result << endl;


    
  return 0;
}