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
    int removeDuplicates(vector<int>& nums) {
      int len = nums.size();
        if(len <= 2){
          return len;
        }

        int j = 2;
        for(int i = 2; i < len; i++){
          if(nums[i] != nums[j-2]){
            nums[j] = nums[i];
            j++;
          }
        }

        return j;
    }
};

int main(){

  vector<int> nums(8);
  nums = {1,1,1,2,2,3,3,3};
  Solution solution;
  int result = solution.removeDuplicates(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << " ";
  }
  cout << endl;
  cout << result << endl;


    
  return 0;
}