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
        int a = 0;
        int b = 0;
        int ad = 0;
        int len = nums.size();
        for(int i = 0; i < len ; i++){
            ad = ad ^ nums[i];
        }
        int mask = 1;
        
        while((mask & ad) == 0){
            mask = mask << 1;          
        }
        for(int i = 0; i < len; i++){
            if((nums[i] & mask) != 0){
                a = a ^ nums[i];
            }else{
                b = b ^ nums[i];
            }
        }
        return {a,b};
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