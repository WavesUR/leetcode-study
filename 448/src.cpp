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


//Space: O(1)
// Time: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> v;
        for(int i = 0; i < len; i++){
            int val = abs(nums[i]) - 1;
            if(nums[val] > 0){
                nums[val] = -nums[val];
            }
        }

        for(int i = 0; i < len; i++){
            if(nums[i] > 0){
                v.push_back(i+1);
            }
        }
        return v;
    }
};

int main(){


    int arr[8] = {4,3,2,7,8,2,3,1};
    vector<int> nums1(arr,arr+8);
	Solution solution;	
 
	vector<int> result = solution.findDisappearedNumbers(nums1);	
    for(int i = 0; i < result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;



    
	return 0;
}