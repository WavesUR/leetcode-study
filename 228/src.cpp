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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.empty()){
            return v;
        }
        string s;
        for(int cur = 0, start = 0; cur < nums.size() ; cur++){
            if(cur == nums.size() - 1 || nums[cur+1] != nums[cur] + 1){
                if(cur == start){
                    s = to_string(nums[start]);
                }else{
                    s = to_string(nums[start]) + "->" + to_string(nums[cur]);
                }
                v.push_back(s);
                start = cur + 1;
            }
        }
        return v;
    }
};

int main(){


    int arr[6] = {0,1,2,4,5,7};
    vector<int> nums1(arr,arr+6);
	Solution solution;	
 
	vector<string> result = solution.summaryRanges(nums1);	
    for(int i = 0; i < result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;



    
	return 0;
}