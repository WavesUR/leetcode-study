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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
      vector<vector<int> > vv;
      if(!root){
        return vv;
      }
      vector<int> v;
      helper(vv, v, sum, root);
      return vv;
    }
    void helper(vector<vector<int> >& vv, vector<int>& v, int sum, TreeNode* root){
        if(!root->left && !root->right){
          if(sum == root->val){
            v.push_back(root->val);
            vv.push_back(v);
            return;
          }
        }
        v.push_back(root->val);
        if(root->left){          
          helper(vv, v, sum-root->val, root->left);
        }

        if(root->right){
          helper(vv, v, sum-root->val, root->right);        
        }
        v.pop_back();
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 2;
vector<vector<int> > result = solution.pathSum(root,sum);

  for(int i = 0; i < result.size(); i++){
    for(int j = 0; j < result[0].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

    
	return 0;
}