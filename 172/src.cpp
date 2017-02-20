#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n > 0){
          n = n / 5;
          sum = sum + n;
        }
        return sum;
    }
};
int main(){
  int n = 5;
  Solution solution;

  int result = solution.trailingZeroes(n);
  cout << result << endl;


    
  return 0;
}