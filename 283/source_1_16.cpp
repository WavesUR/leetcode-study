#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// Space Complexity: O(1), only constant space is used
// Time complexity: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++){
        	if(nums[i] != 0){
      			swap(nums[i],nums[j]);
        		j++;      			
      		}
        }
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