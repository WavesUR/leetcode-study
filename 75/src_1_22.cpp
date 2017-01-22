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
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int i = 0;
        for(int i = 0; i <= end; ){
          if(nums[i] == 0){
            swap(nums[i],nums[start]);
            start++;
            i++;
          }
          else if(nums[i] == 2){
            swap(nums[i],nums[end]);
            end--;
          }else{
            i++;
          }         
        }
    }
};
int main(){

  vector<int>  nums(2);
  nums = {2,1,0,2,1, 0};
  Solution solution;
  solution.sortColors(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << endl;
  }


    
  return 0;
}