#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }

        int l = 0;
        int r = len - 1;
        int c = (int)((l+r)/2);

        while(l<=r){
          if(nums[c] == target){
            return c;
          }else if(nums[c] > target){
            r = c - 1;
          }else{
            l = c + 1;
          }
            c = (int)((l+r)/2);
        }

        return nums[c] > target ? c : c+1;
    }
};

int main(){

  int target = 10;
  int result;
  vector<int> nums(5); 
  nums = {1,3,5,7,9};
  Solution solution;
  result = solution.searchInsert(nums,target);

for (int i = 0; i < nums.size(); ++i)
{
  cout << nums[i] << " ";
}
cout << endl;
  cout << result << endl;

  return 0;
}