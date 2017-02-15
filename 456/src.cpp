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
        if(nums.size() < 3) {
          return false;
        }

        stack<int> my_stack;
        for(int i = 0; i < nums.size(); i++){
          if(!my_stack.empty()){
            if(nums[i] > my_stack.top()){
              my_stack.push(nums[i]);
            }else if(nums[i] < my_stack.top()){
              my_stack.pop();
              if(!my_stack.empty() && nums[i] > my_stack.top()){
                return true;
              }
              my_stack.push(nums[i]);
            }
          }else{
            my_stack.push(nums[i]);
          }
          
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