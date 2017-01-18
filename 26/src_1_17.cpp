#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Time complexity is O(n)
// Space complexity is O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int slow_p = 0;
        for(int fast_p = 1; fast_p < nums.size(); ){
                if(nums[slow_p] == nums[fast_p]){
                fast_p++;
                continue;
            }else{
                nums[slow_p+1] = nums[fast_p];
                fast_p++;
                slow_p++;
            }
        }
        return slow_p+1;
    }
};

int main(){


    int arr[3] = {1,1,2};
    vector<int> nums1(arr,arr+3);
    int result;
	Solution solution;	
 
	result = solution.removeDuplicates(nums1);	

    cout << result << endl;


    
	return 0;
}