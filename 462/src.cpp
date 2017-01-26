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
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0; i < len / 2; i++){
            res = res + nums[len-1-i] - nums[i];
        }
        return res;
    }
};

int main(){

  vector<int> nums;
  nums = {2,3,4,1,2,3};
  Solution solution;
  int result = solution.minMoves2(nums);

  cout << result << endl;


    
  return 0;
}