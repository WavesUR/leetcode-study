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

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo = vector<int>(n,0);
        for(int i = n - 2; i >= 0; i--){
            int min_step = INT_MAX; 
            for(int j = i + 1; j < n && j <= i + nums[i]; j++){
                if(memo[j] != INT_MAX && min_step > memo[j] + 1){
                    min_step = memo[j] + 1;
                }
            } 
            memo[i] = min_step; 
        }
        return memo[0];
    }
};
int main(){
  vector<int>  nums;
  nums = {1,2,0,1};
  Solution solution;

  int result = solution.jump(nums);
  cout << result << endl;


    
  return 0;
}