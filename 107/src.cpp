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
    void helper(TreeNode *root, int level,vector<vector<int> > &result){
      if(!root){
        return;
      }
        if(level >= result.size()){
          vector<int> newvec;
          result.push_back(newvec);
        }
        result[level].push_back(root->val);
        level++;
        helper(root->left,level,result);
        helper(root->right,level,result);
    }
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;       
        int level = 0;
        helper(root,level,result);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
TreeNode *root = new TreeNode(2);
vector<vector<int> > output;

Solution solution;
output = solution.levelOrderBottom(root);

// cout << result << endl;

    
	return 0;
}