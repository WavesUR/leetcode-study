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
    void dfs(TreeNode* root, vector<string>& res, string& s){
      if(!root){
        return;
      }
      if(root->left == NULL && root->right ==NULL){
        res.push_back(s + to_string(root->val));
        return;
      }

      string t = s + to_string(root->val) + "->";
      if(root->left){
        dfs(root->left,res,t);
      }
      if(root->right){
        dfs(root->right,res,t);
      }      
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(root,res,s);
        return res;
    }
};
int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
vector<string> result = solution.binaryTreePaths(root);

cout <<to_string(sum) << endl;
// cout << root->val << endl;
    
	return 0;
}