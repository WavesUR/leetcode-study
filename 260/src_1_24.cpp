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
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int i  = 0; i < nums.size(); i++){
          xor_all = xor_all ^ nums[i];
        }
        int mask = 1;
        while((xor_all & mask) == 0){
          mask = mask << 1;
        }
        int res1 = 0, res2 = 0;
        for(int i = 0; i < nums.size();i++){
            if((mask & nums[i])){
              res1 = res1 ^ nums[i];
            }else{
              res2 = res2 ^ nums[i];
            }
        }
        return {res1,res2};
    }
};


int main(){
  vector<int>  nums;
  nums = {1,2,1,3,2,5};
  Solution solution;

  vector<int> result = solution.singleNumber(nums);
  cout << result[0] << result[1] << endl;


    
  return 0;
}