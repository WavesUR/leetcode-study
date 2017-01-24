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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int cur1 = -1;
        for(int i = len - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                cur1 = i - 1;
                break;
            }

        }

        int cur2 = len - 1;        
        if(cur1 >= 0){
          while(cur2 >= 0 && nums[cur2] <= nums[cur1]){
            cur2--;
          }
          swap(nums[cur1],nums[cur2]);
        }
        reverse(nums.begin()+(cur1+1),nums.end());

    }
};

int main(){

  vector<int> nums;
  nums = {1};
  Solution solution;
  solution.nextPermutation(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << endl;
  }


    
  return 0;
}