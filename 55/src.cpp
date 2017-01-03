#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int i = 0;
        while(i < len - 1){
          if(nums[i] <= sum){
            if(i == 0){
              return false;
            }
            i--;
            sum++;
          }else{
            i += sum + 1;
            sum = 0;
          }
        }
        return true;
    }
};
int main(){
  vector<int>  nums;
  nums = {0,1};
  Solution solution;

  bool result = solution.canJump(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << " ";
  // }
  // cout << endl;
  // cout << result << endl;
  cout << result << endl;


    
  return 0;
}