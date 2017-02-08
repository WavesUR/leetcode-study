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
    int numTrees(int n) {
       vector<int> temp(n+1,0); 
       return helper(temp,n);
    }
    int helper(vector<int>& temp, int n){
      if(n == 0){
        return temp[n] = 1;
      }
      if(n == 1){
        return temp[n] = 1;
      }

      int sum = 0;

      for(int i = n; i > 0; i--){
        int a = temp[i-1] > 0 ? temp[i-1] : helper(temp,n-1);
        int b = temp[n-i] > 0 ? temp[n-i] : helper(temp,n-i);
        sum += a*b;
      }
      return temp[n] = sum;
    }
};

int main(){

  int n = 4;
  Solution solution;
  int result = solution.numTrees(n);

  cout << result << endl;


    
  return 0;
}