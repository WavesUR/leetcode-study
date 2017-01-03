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
    vector<int> getRow(int rowIndex)  {
        vector<int> PT;
        if(rowIndex > 0){
            PT = getRow(rowIndex-1);
 //           vector<int> vc;         
            PT.push_back(1);
            int i = rowIndex -1;
            while(i >= 1){
               PT[i] = PT[i-1]+PT[i];
                i--;
            }  
        }else if(rowIndex == 0){
            PT.push_back(1);
 //           return PT;
        }     
       return PT;
    }  
};

int main(){

    vector<int> PT;
    // int arr[2] = {0,0};
    // vector<int> nums1(arr,arr+2);
    // int arr1[2] = {1,1};
    // vector<int> nums2(arr1,arr1+2);
    // PT.push_back(nums1);
    // PT.push_back(nums2);
	Solution solution;	
    PT = solution.getRow(3);      
    for(int i = 0; i < PT.size();i++){
            cout << PT[i]<< " ";
        
    }
cout << endl;


//    cout << result << endl;


    
	return 0;
}