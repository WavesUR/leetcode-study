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
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while(z != 0){
        	count++;
        	z = z & (z - 1);
        }
        return count;
    }
};
int main(){

  int x = 4;
  int y = 1;
  Solution solution;
  int result = solution.hammingDistance(x,y);
  cout << result << endl;


    
  return 0;
}