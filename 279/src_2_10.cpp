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

//unordered_map
// class Solution {
// public:
//     unordered_map<int,int> my_map;
//     int numSquares(int n) {
//         if(my_map.find(n) != my_map.end()){
//           return my_map[n];
//         }
//         if(n == 0){
//           my_map[n] = 0;
//           return 0;
//         }
//         int min_num = INT_MAX;
//         for(int i = 1; i*i<= n; i++){
//             min_num = min(min_num,numSquares(n-i*i));
//         }
//         my_map[n] = min_num + 1;
//         return my_map[n];
//     }
// };

class Solution {
public:
    int dp(int n, vector<int>& memo){
      if(memo[n] != 0){
        return memo[n];
      }
      int min_num = INT_MAX;
      for(int i = 1; i * i <= n; i++){
        min_num = min(min_num,dp(n-i*i,memo));
      }
      memo[n] = (min_num == INT_MAX ? 0 : min_num + 1);
      return memo[n];
    }
    int numSquares(int n) {
        static vector<int> memo(1000000,0);
        return dp(n,memo);
    }
};

int main(){

  int n = 3;
  Solution solution;
  int result = solution.numSquares(n);
  cout << result << endl;


    
  return 0;
}