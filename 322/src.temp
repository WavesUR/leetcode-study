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
    int * arr;
    int coinChange(vector<int>& coins, int amount) {
        // if(amount <= 0){
        //   return -1;
        // }
        arr = new int[amount+1];
        arr[0] = 0;
        for(int i = 1; i<=amount;i++){
          arr[i] = INT_MAX;
        }

        return helper(coins,amount);
    }
    int helper(vector<int>& coins, int amount){
        if(amount < 0){
          return -1;
        }

        if(arr[amount] != INT_MAX) return arr[amount];

        for(int i = 0; i < coins.size(); i++){
          int temp = helper(coins,amount - coins[i]);
          if(temp >= 0){
            arr[amount] = min(temp + 1, arr[amount]);
          }  
        }
        if(arr[amount] == INT_MAX) arr[amount] = -1;
        return arr[amount];
     
    }
};

int main(){

  vector<int> coins;
  coins = {442,295,365,485};
  int amount = 8091;
  Solution solution;
  int result = solution.coinChange(coins, amount);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}