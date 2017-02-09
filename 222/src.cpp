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
    int countNodes(TreeNode* root) {
        if(!root){
          return 0;
        }
        int height_l = 0, height_r = 0;
        TreeNode* cur_l = root;
        TreeNode* cur_r = root;
        while(cur_l){
          cur_l = cur_l -> left;
          height_l++;
        }
        while(cur_r){
          cur_r = cur_r -> right;
          height_r++;
        }
        if(height_r == height_l){
          return (1 << height_l) + 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int res = solution.countNodes(root);

// cout << result << endl;

    
    return 0;
}