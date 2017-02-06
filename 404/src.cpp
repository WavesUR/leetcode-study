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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
          return 0;
        }
        int count = 0;
        if(root->left && !root->left->left && !root->left->right){
          count = root->left->val;
        }
        count = count+sumOfLeftLeaves(root->right)+sumOfLeftLeaves(root->left);
        return count;
        
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
bool result = solution.sumOfLeftLeaves(root);

cout << result << endl;

    
    return 0;
}