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
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return nums.empty() ? 0 : j;
    }
};

int main(){


    int arr[2] = {0,0};
    vector<int> nums1(arr,arr+2);
    int result;
	Solution solution;	
 
	result = solution.removeDuplicates(nums1);	

    // vector<int>::iterator iter;
    // for(iter=nums1.begin(); iter < nums1.end(); iter++){
    //     cout << *iter <<" ";
    // }
    //                 for(int i=0; i < 2; i++){
    //     cout << nums1[i] <<" ";
    // }
    cout << result << endl;


    
	return 0;
}