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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
          return NULL;
        }

        if(root == p && root == q){
          return root;
        }

        TreeNode *nodex = lowestCommonAncestor(root->left, p , q);
        if(nodex != NULL && nodex != p && nodex != q){         
          return nodex;
        }

        TreeNode *nodey = lowestCommonAncestor(root->right, p , q);
        if(nodey != NULL && nodey != p && nodey != q){         
          return nodey;
        }

        

        if(nodex != NULL && nodey != NULL){
          return root;
        }else if(root == p || root == q){
          return root;
        }else{
          return x == NULL ? y : x;
        }

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
root = solution.lowestCommonAncestor(root,root1,root2);

// cout << result << endl;

    
	return 0;
}