#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool dp(vector<unordered_map<int,bool> >& memo, int mc,int desiredTotal, int key){
      if(memo[desiredTotal - 1].find(key) != memo[desiredTotal-1].end()){
        return memo[desiredTotal-1][key];
      }
      for(int i = mc - 1; i>= 0; i--){
        if(key & (1 << i)){
          key ^= (1 << i); // remove one 1, means occupy one bit, one number
          if(i+1>=desiredTotal || !dp(memo,mc,desiredTotal-i-1,key)){ // opponent cannot win next step, which means we can win
            memo[desiredTotal-1][key] = true;
            key |= (1 << i);
            return true;
          }
          key |= (1 << i);
        }        
      }
      memo[desiredTotal-1][key] = false;
      return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= 1){
          return true;
        }
        if(maxChoosableInteger*(maxChoosableInteger+1) < desiredTotal*2){
          return false;
        }
        vector<unordered_map<int,bool> > memo(desiredTotal);
        int key = (1 << maxChoosableInteger) - 1; // all bit 1
        return dp(memo,maxChoosableInteger,desiredTotal,key);
    }
};

int main(){

  int maxChoosableInteger = 10;
  int desiredTotal = 11;
  Solution solution;
  bool result = solution.canIWin(maxChoosableInteger, desiredTotal);
  cout << result << endl;


    
  return 0;
}