#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Space: O(n)
// Time: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // if(nums.empty()){
        //     return false;
        // }
        unordered_map<int,bool> mymap;
        for(int i = 0; i < nums.size();i++){
            auto t = mymap.find(nums[i]);
            if(t == mymap.end()){
                mymap[nums[i]] = true;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){

	Solution solution;	
	bool result;

    int arr[8] = {4,3,2,7,8,2,3,1};
    vector<int> nums1(arr,arr+8);

	result = solution.containsDuplicate(nums1);	
	cout << result << endl;

    
	return 0;
}