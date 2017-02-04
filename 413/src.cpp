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
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        int sum = 0;
        if(len < 3){
          return 0;
        }
        vector<int> memo(len,0);
        for(int i = len - 3; i >= 0; i--){
          if(A[i] - A[i+1] == A[i+1] - A[i+2]){
            memo[i] = memo[i+1] + 1;
          }
        }
        for(int i = 0; i < len - 2; i++){
          sum = sum + memo[i];
        }
        return sum;
    }
};
int main(){

  vector<int> A = {1,2,3,4,5};
  Solution solution;
  int result = solution.numberOfArithmeticSlices(A);
  cout << result << endl;


    
  return 0;
}