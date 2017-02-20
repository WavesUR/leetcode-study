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

//Time: O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int n = nums.size();
    	int left = 1;
    	int right = n - 1;
    	while(left < right){
    		int mid = left + (right-left)/2;
    		int c = count(nums,mid);
    		if(c <= mid) {
    			left = mid + 1;
    		}else{
    			right = mid;
    		}
    	}
    	return left; // or right


    }
    int count(vector<int>& nums, int target){
    	int count = 0;
    	for(int i = 0; i < nums.size();i++){
    		if(nums[i] <= target){
    			count++;
    		}
    	}
    	return count;
    }
};



int main(){

  vector<int> nums;
  nums = {1, 2, 2, 3, 4, 5, 6, 7};
  Solution solution;
  int result = solution.findDuplicate(nums);
  cout << result << endl;


    
  return 0;
}