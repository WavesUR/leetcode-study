#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        int count_one = 0;
        int count_zero = 0;
        int max_len = 0;
        map[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count_zero++;
            }else{
                count_one++;
            }
            if(map.find(count_one-count_zero) == map.end()){
                map[count_one-count_zero] = i;
            }else{
                max_len = max(max_len,i-map[count_one-count_zero]);
            }
        }
        return max_len;
    }
};
int main(){

    vector<int> nums = {0,1};
    int result;
    Solution solution;
    result = solution.findMaxLength(nums);
    cout << result << endl; 


    
	return 0;
}