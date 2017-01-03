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
    void flatten(TreeNode* root) {
        TreeNode * temp = helper(root);
    }

    TreeNode* helper(TreeNode* root){
      if(!root){
        return NULL;
      }
      if(!root->left && !root->right){
        return root;
      }
      TreeNode * tempnode1, * tempnode2;
      
      tempnode1 = helper(root->left);
      tempnode2 = helper(root->right);
      
      if(tempnode1 && tempnode2){
        tempnode1 -> right = root->right;
        root->right = root->left;
        root->left = NULL;
        return tempnode2;
      }else if(tempnode1){
        root->right = root ->left;
        root->left = NULL;
        return tempnode1;
      }else{
        return tempnode2;
      }


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