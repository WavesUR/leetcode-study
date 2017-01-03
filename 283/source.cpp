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
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
        // while(j<len){
        //     nums[j] = 0;
        //     j++;
        // }    
    }
};

int main(){


     int arr[5] = {0,1,0,3,12};
    vector<int> nums1(arr,arr+5);
    vector<int> result;
	Solution solution;	
 
	solution.moveZeroes(nums1);	

    vector<int>::iterator iter;
    for(iter=nums1.begin(); iter < nums1.end(); iter++){
        cout << *iter <<" ";
    }
    //                 for(int i=0; i < 2; i++){
    //     cout << nums1[i] <<" ";
    // }
    cout << endl;


    
	return 0;
}