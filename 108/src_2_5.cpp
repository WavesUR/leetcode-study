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
    TreeNode* dfs(vector<int>& nums, int start, int end){
      if(start > end){
        return NULL;
      }
      if(start == end){
        TreeNode *node = new TreeNode(nums[start]);
        return node;
      }

      int mid = start + (end-start)/2;
      TreeNode* node = new TreeNode(nums[mid]);
      node->left = dfs(nums,start, mid - 1);
      node->right = dfs(nums,mid+1,end);
      return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node = dfs(nums,0,nums.size()-1);
        return node;
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