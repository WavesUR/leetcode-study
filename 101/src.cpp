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
    bool helper(TreeNode* root1, TreeNode *root2){
      if(!root1 && !root2){
        return true;
      }
      if(!root1 || !root2){
        return false;
      }

      if(root1->val == root2->val){
        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
      }else{
        return false;
      }

    }
    bool isSymmetric(TreeNode* root) {
      if(!root){
        return true;
      }
      return helper(root->left, root->right);

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
bool result = solution.isSymmetric(root);

cout << result << endl;

    
	return 0;
}