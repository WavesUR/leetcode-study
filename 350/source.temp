#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int i = 0, j = 0; 
        while((i < nums1_size) && (j < nums2_size)){
           if(nums1[i] == nums2[j]){
            result.push_back(nums1[i]);
            i++;
            j++;
           } else if (nums1[i] < nums2[j])
           {
            i++;
           }else{
            j++;
           }
        }
    return result;
    }
};

int main(){

	
    int arr[2] = {5,1};
    int arr1[2] = {1,2};
    vector<int> nums1(arr,arr+5);
    vector<int> nums2(arr1,arr1+2);

    vector<int> result;
	Solution solution;	


    // for(int i = 0; i < 10; i++){
    // 	num[i] = i%10;
    // }   
	result = solution.intersect(nums1,nums2);	

    vector<int>::iterator iter;
    for(iter=result.begin(); iter < result.end(); iter++){
        cout << *iter <<" ";
    }
    //                 for(int i=0; i < 2; i++){
    //     cout << nums1[i] <<" ";
    // }
    cout << endl;

//	cout << result << endl;

    
	return 0;
}