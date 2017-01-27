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

//Time: O(32*n) = O(n)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
      int len = nums.size();
      if(len < 2){
        return 0;
      }
      int res = 0;
      int i = 0;
      int count0 = 0;
      int count1 = 0;
      while(i < 32){
        for(int j = 0; j < len; j++){
          if(nums[j]%2==1){
            count1++;
          }else{
            count0++;
          }
          nums[j] = nums[j] >> 1;
        }
        res = res + count1 * count0;
        count0 = 0;
        count1 = 0;
        i++;
      }

        return res;
    }
};
int main(){

  vector<int> nums = {4,14,2};
  Solution solution;
  int result = solution.totalHammingDistance(nums);
  cout << result << endl;


    
  return 0;
}