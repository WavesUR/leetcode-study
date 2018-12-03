#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <utility> 
using namespace std;

// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    bool pair_compare(pair<int, int>& a, pair<int,int>& b){
      if(a.first > b.first && a.second > b.second){
        return true;
      }else{
        return false;
      }
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if(len <= 1){
          return len;
        }
        sort(envelopes.begin(), envelopes.end());
        int max_g = 1;
        vector<int> memo = vector<int>(len, 1);
        for(int i = 1; i < len; i++){
          for(int j = 0; j < i; j++){
            if(pair_compare(envelopes[i],envelopes[j])){
              memo[i] = max(memo[i], memo[j] + 1);
            }
          }
          max_g = max(memo[i], max_g);
        }
        return max_g;
    }
    
};



int main(){
  vector<pair<int, int> > nums;
  nums = {make_pair(4,5), make_pair(4,6),make_pair(6,7),make_pair(2,3), make_pair(1,1)};
  Solution solution;
  int result = solution.maxEnvelopes(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}