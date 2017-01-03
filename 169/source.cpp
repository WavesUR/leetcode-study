#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main(){


    int arr[6] = {0,-1,0,0,0,-1};
    vector<int> nums1(arr,arr+6);
    int result;
	Solution solution;	
 
	result = solution.majorityElement(nums1);	

    vector<int>::iterator iter;
    for(iter=nums1.begin(); iter < nums1.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl;

    cout << result << endl;


    
	return 0;
}