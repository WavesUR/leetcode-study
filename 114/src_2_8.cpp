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
    TreeNode* dfs(TreeNode* root){
      if(!root){
        return NULL;
      }
      if(!root->left && !root->right){
        return root;
      }
      TreeNode* left_last = dfs(root->left);
      TreeNode* right_last = dfs(root->right);
      if(left_last){
        left_last->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }  
      if(!right_last){
        right_last = left_last;
      }   
      return right_last;
    }

    void flatten(TreeNode* root) {
        TreeNode* temp = dfs(root);
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
solution.flatten(root);

// cout << result << endl;

    
	return 0;
}