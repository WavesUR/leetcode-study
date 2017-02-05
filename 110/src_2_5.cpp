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
    int dfs(TreeNode* root){
      if(!root){
        return 0;
      }
      if(!root->left && !root->right){
        return 1;
      }
      int l = 0;
      int r = 0;
      if(root->right){
          r = dfs(root->right);
      }
      if(root->left){
          l = dfs(root->left);
      }
      if(l == -1 || r == -1 || abs(l-r) > 1 ){
        return -1;
      }else{
        return max(l,r)+1;
      }      

    }
    bool isBalanced(TreeNode* root) {
        int res = dfs(root);
        return res == -1 ? false:true;
    }
};

int main(){

TreeNode *root = NULL;
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
bool result = solution.isBalanced(root);

cout << result << endl;

    
	return 0;
}