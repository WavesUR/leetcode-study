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


//Space: O(1)
// Time: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;        
        if(nums.empty()){
            return res;
        }
        for(int i = 0; i < nums.size(); i++){
            int temp = abs(nums[i]) - 1;
            if(nums[temp] < 0){
                res.push_back(temp+1);
            }
            nums[temp] = -nums[temp];
        }

        return res;

    }
};

int main(){


    int arr[8] = {4,3,2,7,8,2,3,1};
    vector<int> nums1(arr,arr+8);
	Solution solution;	
 
	vector<int> result = solution.findDuplicates(nums1);	
    for(int i = 0; i < result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;



    
	return 0;
}