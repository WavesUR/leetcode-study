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
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s2; // always store the maximum value
        int s3 = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
          if(nums[i] < s3){
            return true;
          }
          while(!s2.empty() && nums[i] > s2.top()){
            s3 = s2.top();
            s2.pop();
          }
          s2.push(nums[i]);
        }
        return false;
    }
};

int main(){

  vector<int> nums = {3,5,0,3,4};
  Solution solution;
  bool result = solution.find132pattern(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}