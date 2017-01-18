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


// //Space: O(1)
// // Time: O(n)
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k = k % nums.size();
//         int count = 0;
//         for(int start = 0; count < nums.size(); start++){ 
//         	int current_cur = start;
//         	int prev_value = nums[current_cur];
//         	do{
//         		int next_cur = (current_cur + k) % nums.size();
//         		int temp = nums[next_cur];
//         		nums[next_cur] = prev_value;
//         		current_cur = next_cur;
//         		prev_value = temp;
//         		count++;
//         	}while(current_cur != start);
//         }       
//     }
// };

// Space: O(1)
// Time: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k != 0){
	        reverse(nums.begin(),nums.end());
			reverse(nums.begin(),nums.begin()+k);  
			reverse(nums.begin()+k,nums.end());   
        }
  
    }
};


int main(){


    int arr[3] = {1,2,3};
    vector<int> nums1(arr,arr+3);
	Solution solution;	
 
	solution.rotate(nums1,2);	
    for(int i = 0; i < nums1.size();i++){
        cout << nums1[i] << " ";
    }
    cout << endl;



    
	return 0;
}