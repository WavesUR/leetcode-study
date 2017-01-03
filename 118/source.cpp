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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > PT;


        if(numRows > 1){
            PT = generate(numRows-1);
            vector<int> vc;
            int i = 0;
            while(i < numRows){
                if(i == 0 || i == numRows -1){
                    vc.push_back(1);
                }else{
                    vc.push_back(PT[numRows-2][i-1]+PT[numRows-2][i]);
                }
                i++;
            } 
            PT.push_back(vc);  
        }else if(numRows == 1){
            vector<int> v1(1, 1);
            PT.push_back(v1);
 //           return PT;
        }

     
       return PT;
    }  
};

int main(){

    vector<vector<int> > PT;
    // int arr[2] = {0,0};
    // vector<int> nums1(arr,arr+2);
    // int arr1[2] = {1,1};
    // vector<int> nums2(arr1,arr1+2);
    // PT.push_back(nums1);
    // PT.push_back(nums2);
	Solution solution;	
    PT = solution.generate(5);      
    for(int i = 0; i < PT.size();i++){
        for(int j = 0; j < PT[i].size();j++){
            cout << PT[i][j] << " ";
        }
        cout << endl;
    }



//    cout << result << endl;


    
	return 0;
}