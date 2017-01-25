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
    int singleNumber(vector<int>& nums) {
    	int a = 0;
    	int b = 0;
        for(int i = 0; i < nums.size();i++){
        	int temp_a = (a & ~b & ~nums[i]) | (~a & b & nums[i]);
        	int temp_b = (~a & ~b & nums[i]) | (~a & b & ~nums[i]);
        	a = temp_a;
        	b = temp_b;
        }


        return b;
    }
};


int main(){

vector<int> nums;
nums = {0,1,0,1,3,0,1};
Solution solution;
int result = solution.singleNumber(nums);
cout << result << endl;
    
return 0;
  
}