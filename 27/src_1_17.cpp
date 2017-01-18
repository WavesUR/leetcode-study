#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;


//Space: O(1)
// Time: O(n)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       if(nums.size() == 0){
            return 0;
       } 
       int i = 0, j = nums.size() - 1;
       while(i<=j){
            if(nums[i] == val){
                nums[i] = nums[j];
                j--;
            }else{
               i++; 
            }           
       }
       return i;
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