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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      int len = nums.size();
        if(len == 0){
          return NULL;
        }

        return help(nums, 0, len-1);

    }
    TreeNode* help(vector<int>& nums, int start, int last){
      if(start > last){
        return NULL;
      }
      int mid = start+(last-start)/2;
      TreeNode *result = new TreeNode(nums[mid]);
      result->left = help(nums, start, mid-1);
      result->right = help(nums, mid+1, last);
      return result;
    }
};

int main(){

  vector<int> nums(5);
  nums = {0,1,2,3,4};
  Solution solution;
  TreeNode* result = solution.sortedArrayToBST(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  // cout << result << endl;


    
  return 0;
}