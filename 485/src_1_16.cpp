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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int MaxCount = 0;
        int count = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 1){
                if(i != 0 && nums[i-1] == 0){
                    if(MaxCount < count){
                        MaxCount = count;
                    }
                    count = 0;
                }
                count++;
            }
        }
        return max(MaxCount,count);
    }
};

int main(){


    int arr[6] = {1,0,1,1,0,1};
    vector<int> nums1(arr,arr+6);
    int result;
    Solution solution;  
 
    result = solution.findMaxConsecutiveOnes(nums1);   

    vector<int>::iterator iter;
    for(iter=nums1.begin(); iter < nums1.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl;

    cout << result << endl;


    
    return 0;
}