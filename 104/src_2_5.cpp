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
        if(!root->left && !root->right){
          return 1;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+ 1;
    }
};

int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
int result = solution.maxDepth(root);

cout << result << endl;

    
	return 0;
}