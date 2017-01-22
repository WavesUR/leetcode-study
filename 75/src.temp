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
      int len = nums.size();
      if(len == 0){
        return;
      }
      int i = 0, j = len - 1, m = 0;
      int temp = 0;
      while(m <= j){
        cout << i << m << j << endl;
      if(nums[m] == 0){
        swap(nums[i],nums[m]);
        i++;
        m++;
      }
      else if(nums[m] == 2){
        swap(nums[j],nums[m]);
        j--;
      }
      else{
        m++;
      } 
      cout << i << m << j << endl;       
      }

    }
};

int main(){

  vector<int>  nums(2);
  nums = {2, 0};
  Solution solution;
  solution.sortColors(nums);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << endl;
  }


    
  return 0;
}