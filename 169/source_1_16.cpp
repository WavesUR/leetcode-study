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
//         int len = nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[int(len/2)];
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, cand = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == cand){
                count++;
            }else if(count==0){
                count++;
                cand = nums[i];
            }else{
                count--;
            }
        }
        return cand;
    }
};


int main(){


    int arr[6] = {0,-1,0,-1,-1,-1};
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