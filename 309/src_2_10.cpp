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
    int dp(vector<int>& prices, int pos, vector<int>& memo){
      memo[pos] = 
    }
    int maxProfit(vector<int>& prices) {
       if(prices.empty()){
        return 0;
       } 
       vector<int> memo(prices.size()+1,0);
    }
};
int main(){

  vector<int> prices;
  prices = {1,2,3,0,2};
  Solution solution;
  int result = solution.maxProfit(prices);
  cout << result << endl;


    
  return 0;
}