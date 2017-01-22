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
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int  j = 0; j < nums.size(); j++){
          if(i >= 2 && nums[j] == nums[i-2]){
              continue;          
          }
          if(i != j){
            swap(nums[i],nums[j]);            
          }
          i++;           
        }
        return i;
    }
};

int main(){

  vector<int> nums(8);
  nums = {1,1,1,2,2,3,3,3};
  Solution solution;
  int result = solution.removeDuplicates(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << " ";
  }
  cout << endl;
  cout << result << endl;


    
  return 0;
}