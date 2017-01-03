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
    int maxDepth(TreeNode* root) {
      if(!root){
        return 0;
      }
       int left = 0;
       int right = 0;
       if(root->left){
        left = maxDepth(root->left);
       }
       if(root->right){
        right = maxDepth(root->right);
       }
       return max(left,right)+1;
    }
};

int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
int result = solution.maxDepth(root);

cout << result << endl;

    
	return 0;
}