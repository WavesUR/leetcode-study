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
    bool increasingTriplet(vector<int>& nums) {
    	int len = nums.size();
    	if(len < 3){
    		return false;
    	}
        int temp1 = INT_MAX;
        int temp2 = INT_MAX;
        for(int i = 0; i < len ; i++){
        	if(nums[i] <= temp1){
        		temp1 = nums[i];
        	}else if(nums[i] <= temp2){
        		temp2 = nums[i];
        	}else{
        		return true;
        	}
        }
        return false;
    }
};
int main(){

  vector<int> nums;
  nums = {1,2,3,1,2,1};
  Solution solution;
  bool result = solution.increasingTriplet(nums);
  cout << result << endl;


    
  return 0;
}