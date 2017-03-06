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
        if(n == 0){
          return {0};
        }
        vector<int> res = grayCode(n-1);
        int offset = pow(2,n-1);
        int len = res.size();
        for(int i = len -1 ; i >= 0; i--){
          res.push_back(res[i]+offset);
        }
        return res;
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