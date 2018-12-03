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
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty()){
            return 0;
        }
        int n = cost.size();
        if(n == 1){
            return cost[0];
        }
        if(n == 2){
            return min(cost[0], cost[1]);
        }

        vector<int> memo(n,0);
        memo[0] = cost[0];
        memo[1] = cost[1];
        for(int i = 2; i < n; i++){
            memo[i] = min(memo[i-2], memo[i-1]) + cost[i];
        }
        return min(memo[n - 1], memo[n - 2]);

    }
};


int main(){

  vector<int> cost;
  cost = {0,0,0,1};
  Solution solution;
  int result = solution.minCostClimbingStairs(cost);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}