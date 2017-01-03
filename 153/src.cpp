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
    int findMin(vector<int>& nums) {



        int l = 0;
        int r = nums.size() - 1;

        if(nums[l]<=nums[r]){
          return nums[l];
        }
        while(l + 1<r){
          int c = (int)(l+(r-l)/2);
          if(nums[c]>nums[l]){
            l = c;
          }

          if(nums[c] < nums[r]){
            r = c;
          }
        }
        return nums[r];

    }
};

int main(){

  int result;
  vector<int> nums(12); 
  nums = {11,0,1,2,3,4,5,6,7,8,9,10};
  Solution solution;
  result = solution.findMin(nums);

for (int i = 0; i < nums.size(); ++i)
{
  cout << nums[i] << " ";
}
cout << endl;
  cout << result << endl;

  return 0;
}