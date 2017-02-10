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
    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      if(len <= 1){
        return 0;
      }
      vector<int> s0(len,0); // ready to buy or wait
      vector<int> s1(len,0); // ready to sell or wait
      vector<int> s2(len,0); // cooldown
      s0[0] = 0;
      s1[0] = -prices[0];
      s2[0] = INT_MIN;
      for(int i = 1; i < len; i++){
        s0[i] = max(s0[i-1],s2[i-1]);
        s1[i] = max(s1[i-1],s0[i-1]-prices[i]);
        s2[i] = s1[i-1] + prices[i];
      }
      return max(s0[len-1],s2[len-1]);
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