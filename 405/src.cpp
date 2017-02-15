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
    string toHex(int num) {
        vector<char> v = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string s;
        int mask = 0x0000000f;
          unsigned num_temp = num;
          do{
            int index = num_temp & mask;
            s = v[index]+s;
            num_temp = num_temp>> 4;
          }while(num_temp);        
        return s;
    }
};

int main(){

  int m = 26;
  Solution solution;
  string result = solution.toHex(m);
  cout << result << endl;


    
  return 0;
}