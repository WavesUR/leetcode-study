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
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){
          mid = left + ((right - left) >> 1);
          if(nums[mid] <= nums[right]){
            right = mid;
          }else{
            left = mid + 1;
          }
        }
        return nums[right];
    }
};

int main(){

  int result;
  vector<int> nums(12); 
  nums = {1,2,3,4,5,6,7,8,9,10};
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