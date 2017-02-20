#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        // nums = temp;
        int mid = nums.size()/2;
        for(int i = 0; i < nums.size(); i++){
            if(i%2==0){
                nums[i] = temp[i/2];
            }else{
                nums[i] = temp[mid+i/2];
            }
        }
    }
};



int main(){

  vector<int> nums = {1,3,2,2,3,1};
  Solution solution;
  solution.wiggleSort(nums);
  for(auto num:nums){
    cout << num << endl;
  }


    
  return 0;
}