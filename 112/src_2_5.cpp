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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
          return false;
        }
        if(!root->left && !root->right){
          if(sum == root->val){
            return true;
          }else{
            return false;
          }
        }
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val) ? true:false;      
    }
};
int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
bool result = solution.hasPathSum(root,sum);

cout << result << endl;

    
	return 0;
}