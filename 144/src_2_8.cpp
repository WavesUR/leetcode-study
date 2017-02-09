#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//recursive
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<int>& res){
//       if(!root){
//         return;
//       }

//       res.push_back(root->val);
//       dfs(root->left,res);
//       dfs(root->right,res);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if(!root){
//           return res;
//         }
//         dfs(root,res);
//         return res;
//     }
// };
//iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      // if(!root){
      //   return res;
      // }
      stack<TreeNode*> s;
      TreeNode* cur = root;
      while(cur || !s.empty()){
        if(cur){
          res.push_back(cur->val);
          s.push(cur->right);
          cur = cur -> left;
        }else{
          cur = s.top();
          s.pop();
        }
      }
      return res;
    }
};
int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
vector<int> res = solution.preorderTraversal(root);

// cout << result << endl;

    
	return 0;
}