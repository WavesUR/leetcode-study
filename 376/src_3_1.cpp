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

//Time: O(n)
//Space: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){
          return nums.size();
        }
        int up  = 1, down = 1;

        for(int i = 1; i < nums.size(); i++){
          if(nums[i] > nums[i-1]){
            up = down + 1;
          }else if(nums[i] < nums[i-1]){
            down = up + 1;
          }
        }
        return max(down,up);
    }
};

int main(){

  vector<int> nums= {1,17,5,10,13,15,10,5,16,8};
  Solution solution;
  int result = solution.wiggleMaxLength(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}