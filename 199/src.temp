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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        // if(!root){
        //   return result;
        // }
        int n = 0;
        helper(root,result, n);
        return result;

    }
    void helper(TreeNode* root, vector<int>& result, int n){
      if(!root){
        return;
      }
      if(n == result.size()){
        result.push_back(root->val);
      }
      helper(root->right,result, n+1);
      helper(root->left,result, n+1);
    }
};

int main(){

  vector<int> result;
  TreeNode* root;
  Solution solution;
  result = solution.rightSideView(root);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  // cout << result << endl;


    
  return 0;
}