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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
          return NULL;
        }
        root -> left = invertTree(root->left);
        root -> right = invertTree(root->right);
        swap(root -> left, root -> right);
        return root;
    }
};
int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
root = solution.invertTree(root);

// cout << result << endl;

    
	return 0;
}