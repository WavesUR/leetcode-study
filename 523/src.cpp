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
    bool checkSubarraySum(vector<int>& nums, int k) {
      if(nums.size() < 2){
          return false;
      }
        vector<int> memo(nums.size());
        memo[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
          memo[i] = memo[i-1] + nums[i];
        }
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size();i++){
          if(k == 0){
            if( i != 0 && (memo[i] == 0)){
             return true;              
            }             
          }else{
            if( i != 0 && (memo[i] % k == 0)){
             return true;              
            } 
            if(map.find(memo[i]%k) == map.end()){
              map[memo[i]%k] = 0;
            }
            map[memo[i]%k]++;
            if(map[memo[i]%k] == 2){
              return true;
            }             
          }




        }
        return false;
    }
};

int main(){

  vector<int> nums = {0,0};
  int k = 0;
  Solution solution;
  bool result = solution.checkSubarraySum(nums, k);
  cout << result << endl;


    
  return 0;
}