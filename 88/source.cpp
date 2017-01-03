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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1, j = n-1, k = m-1;
        while(k >= 0  && j >=0){
            if(nums1[k] >= nums2[j]){
                nums1[i] = nums1[k];
                k--;
                i--;
            }else{
                nums1[i] = nums2[j];
                i--;
                j--;               
            }
        }
        while(j >= 0){
            nums1[i] = nums2[j];
            i--;
            j--;
        }
    }
};

int main(){

    int arr[8] = {0,1,3,4,7};
    vector<int> nums1(arr,arr+8);
    int arr1[3] = {5,6,7};
    vector<int> nums2(arr1,arr1+3);
	Solution solution;	
    solution.merge(nums1,5,nums2,3);      
    for(int i = 0; i < nums1.size();i++){
            cout << nums1[i]<< " ";
        
    }
cout << endl;


//    cout << result << endl;


    
	return 0;
}