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
    vector<int> grayCode(int n) {

        vector<int> result(pow(2,n),0);
        helper(result,n);
        return result;
    }
    void helper(vector<int>& result, int n){
        if(n == 0){
          result[0] = 0;
//          result[1] = 1;
          return;
        }
        helper(result,n-1);
        int offset = pow(2,n-1);
        for(int i = 0; i < offset; i++){
          result[offset+i] = result[offset-i-1] + offset;
        }

    }
};

int main(){

  int n = 3;
  Solution solution;
  vector<int> result = solution.grayCode(n);
  for(int i = 0; i< result.size();i++){
    cout << result[i] << endl;
  }
  //out << result << endl;


    
  return 0;
}