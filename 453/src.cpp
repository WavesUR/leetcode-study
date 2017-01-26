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

//Time: O(n)
//Space: O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_nums = INT_MAX;
        int res = 0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
        	sum = sum + nums[i];
        	min_nums = min_nums > nums[i] ? nums[i] : min_nums;
        }
        return res = sum - min_nums * nums.size();
    }
};


int main(){

vector<int> nums;
nums = {1,2,3};
Solution solution;
int result = solution.minMoves(nums);
cout << result << endl;
    
return 0;
  
}