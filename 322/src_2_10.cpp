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
    int dp(vector<int>& coins, int amount, vector<int>& memo){
      if(amount == 0){
        return 0;
      }
      if(memo[amount] != 0){
        return memo[amount];
      }
      int min_num = INT_MAX;
      for(int i = 0; i < coins.size(); i++){
        if(amount >= coins[i]){
          int res = dp(coins,amount - coins[i],memo);
          if(res >= 0 && res < min_num){
            min_num = res + 1;
          }
        }       
      }
      memo[amount] = (min_num == INT_MAX) ? -1 : min_num;
      return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
      if(amount < 0){
        return -1;
      } 
      vector<int> memo(amount+1,0); 
      return dp(coins,amount,memo);
    }
};

int main(){

  vector<int> coins;
  coins = {1,2,3};
  int amount = 4;
  Solution solution;
  int result = solution.coinChange(coins, amount);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}