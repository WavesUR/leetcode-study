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
    unordered_map<int,int> mymap;
    int combinationSum4(vector<int>& nums, int target) {
      if(nums.size() == 0 || target < 0){
        return 0;
      }
      if(target == 0){
        return 1;
      }
      auto found = mymap.find(target);
      if(found != end(mymap)) return found->second;

      int count = 0;
      for(int i = 0; i < nums.size();i++){
        count += combinationSum4(nums,target-nums[i]);
      }
      return mymap[target] = count;
    }

};

int main(){

  vector<int> nums;
  nums = {3,33,333};
  int target = 10000;
  Solution solution;
  int result = solution.combinationSum4(nums,target);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}