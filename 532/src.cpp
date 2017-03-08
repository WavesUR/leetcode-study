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
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty() || k < 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 1;
        int num = 0;
        while(right < nums.size()){
            while(left != 0 && nums[left] == nums[left-1]){
                left++;
            }
            if(left == right){
                right++;
                continue;
            }
            if(nums[right]-nums[left] == k){
                num++;
                left++;
                right++;
            }else if(nums[right]-nums[left] < k){
                right++;
            }else{
                left++;
            }
        }
        return num;
    }
};

int main(){

vector<int> intervals = {1, 3, 1, 5, 4};


Solution solution;
int res = solution.findPairs(intervals,0);

cout << res << endl;

    
    return 0;
}