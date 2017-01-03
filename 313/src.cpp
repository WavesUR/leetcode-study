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
#include <queue>          // std::priority_queue
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int> > pq;
    }
};

int main(){

  vector<int> nums;
  nums = {2, 7, 13, 19};
  int k = 12;
   Solution solution;
   int result = solution.nthSuperUglyNumber(k,nums);
 // for(int i = 0; i < result.size();i++){
 //    cout << result[i] << endl;
 // }
   cout << result << endl;


    
  return 0;
}