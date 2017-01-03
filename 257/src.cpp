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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> v;      
      if(!root){
        return v;
      }
        string s;
        helper(root,s,v);
        return v;
    }

    void helper(TreeNode* root, string & s, vector<string> & v){
      if(!root->left && !root->right){
        s.push_back(char('0' + root->val));

        v.push_back(s);
        
        return;
      }
      if(root->left){
        string temp = s;
        s = s + char('0' + root->val) + "->";
        helper(root->left,s,v);
        s = temp;
      }

      if(root->right){
        string temp = s;
        s = s + char('0' + root->val) + "->";
        helper(root->right,s,v);
        s = temp;
      }
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