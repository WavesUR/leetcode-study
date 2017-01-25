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
    	int res = 0;
        for(int i = 0; i < nums.size();i++){
        	res = res ^ nums[i];
        }
        return res;
    }
};


int main(){

vector<int> nums;
nums = {0,1,0,1,5};
Solution solution;
int result = solution.singleNumber(nums);
cout << result << endl;
    
return 0;
  
}