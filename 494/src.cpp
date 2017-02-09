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
#include <utility>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int S, int start,unordered_map<string,int>& my_map){
      string key = to_string(S)+"."+to_string(start);
        if(my_map.find(key)!= my_map.end()){
          return my_map[key];
        }
        int res;
        if(start == nums.size()){
            if(S == 0){
              res = 1;
            }else{
              res = 0;
            } 
//           my_map[key] = res;
           return res;             
          }       
        res = dfs(nums,S+nums[start],start+1,my_map) + dfs(nums,S-nums[start],start+1,my_map);
        my_map[key] = res;
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
      if(nums.empty()){
        return 0;
      }
      unordered_map<string,int > my_map;
      return dfs(nums,S,0,my_map);
    }
};

int main(){

  vector<int> nums = {1, 0};
  Solution solution;
  int result = solution.findTargetSumWays(nums,1);

  cout << result << endl;


    
  return 0;
}