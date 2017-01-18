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
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0){
            return;
        }
        int cur1 = m-1;
        int cur2 = n-1;
        int cur3 = m+n-1;
        while(cur1 >= 0 && cur2 >= 0){
            if(nums1[cur1] >= nums2[cur2]){
                nums1[cur3] = nums1[cur1];
                cur1--;
                cur3--;
            }else if(nums1[cur1] < nums2[cur2]){
                nums1[cur3] = nums2[cur2];
                cur2--;
                cur3--;
            }
        }
        while(cur2 >=0){
                nums1[cur3] = nums2[cur2];
                cur2--;
                cur3--;
        }

    }
};

int main(){

    int arr[2] = {1,0};
    vector<int> nums1(arr,arr+2);
    int arr1[1] = {2};
    vector<int> nums2(arr1,arr1+1);
	Solution solution;	
    solution.merge(nums1,1,nums2,1);      
    for(int i = 0; i < nums1.size();i++){
            cout << nums1[i]<< " ";
        
    }
cout << endl;

    
	return 0;
}