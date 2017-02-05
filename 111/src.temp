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
    int minDepth(TreeNode* root) {
        if(!root){
          return 0;
        }
        int left_len = minDepth(root->left);
        int right_len = minDepth(root->right);
        if(left_len == 0 || right_len == 0){
          return left_len+right_len+1;
        }else{
         return min(left_len,right_len)+1;         
        }

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int result = solution.minDepth(root);

cout << result << endl;

    
	return 0;
}