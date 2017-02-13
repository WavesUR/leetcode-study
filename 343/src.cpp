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
    int integerBreak(int n) {
      if(n == 2){
        return 1;
      }
      if(n == 3){
        return 2;
      }
      if(n%3 == 0){
        return pow(3,n/3);
      }
      if(n%3 == 1){
        return 2 * 2 * pow(3,(n-4)/3);
      }
      return 2 * pow(3,(n-2)/3);

    }
};

int main(){
  vector<int> nums;
  Solution solution;

  int result = solution.integerBreak(8);
  cout << result << endl;
  // cout << result << endl;


    
  return 0;
}