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
//Time: O(n)
// Space: O(n) 
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<int>& res){
//       if(!root){
//         return;
//       }
//       if(!root->left && !root->right){
//         res.push_back(root->val);
//         return;
//       }
//       dfs(root->left,res);
//       res.push_back(root->val);
//       dfs(root->right,res);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         dfs(root,res);
//         return res;
//     }
// };

//iterative
 //Time: O(n)
// Space: O(n) 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root){
          return res;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()){
          if(cur){
            s.push(cur);
            cur = cur->left;
          }else{
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
          }
          
        }
        return res;
    }
};
int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
vector<int> res = solution.inorderTraversal(root);

// cout << result << endl;

    
	return 0;
}