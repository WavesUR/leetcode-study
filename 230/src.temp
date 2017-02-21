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
  int r;
  int res;
public:
    void kthSmallest_helper(TreeNode* root) {
        if(!root || r < 1){
          return;
        }
        kthSmallest_helper(root->left);
        if(r == 1){
          res = root->val;
          r--;
        }else{
          r--;
        }
        kthSmallest_helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
          return 0;
        }
        r = k;
        kthSmallest_helper(root);
        return res;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
int k = 3;
Solution solution;
int result = solution.kthSmallest(root, k);

// cout << result << endl;

    
  return 0;
}