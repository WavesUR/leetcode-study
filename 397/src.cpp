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
    int integerReplacement(int n) {
        unsigned int nn = n;
        int c = 0;
        while(nn != 1){
          if((nn & 1) == 0){
            nn = nn >> 1;
          }else if( nn == 3 || ((nn >> 1)&1) == 0){
            nn--;
          }else{
            nn++;
          }
          c++;
        }
        return c;
    }
};

int main(){

  int m = 7;
  Solution solution;
  int result = solution.integerReplacement(m);
  cout << result << endl;


    
  return 0;
}