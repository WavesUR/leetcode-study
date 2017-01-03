#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int helper(TreeNode* root){
      if(!root){
        return 0;
      }
      int left_len = helper(root->left);
      int right_len = helper(root->right);
      if(left_len == -1 || right_len == -1 || abs(left_len-right_len)>1){
        return -1;
      }else{
        return max(left_len,right_len)+1;
      }
    }


    bool isBalanced(TreeNode* root) {

        int result = helper(root);
        return result == -1 ? false : true;

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
bool result = solution.isBalanced(root);

cout << result << endl;

    
	return 0;
}