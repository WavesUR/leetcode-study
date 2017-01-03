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
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int res = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != val){
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};

int main(){


     int arr[5] = {0,1,0,3,12};
    vector<int> nums1(arr,arr+5);
    int result;
    int val = 1;
	Solution solution;	
 
	result = solution.removeElement(nums1,val);	

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