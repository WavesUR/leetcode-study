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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; i++){
          res = res ^ i ^ nums[i];
        }
        return res;
    }
};


int main(){

vector<int> nums;
nums = {0,1,2,4,5,6};
Solution solution;
int result = solution.missingNumber(nums);
cout << result << endl;
    
return 0;
  
}