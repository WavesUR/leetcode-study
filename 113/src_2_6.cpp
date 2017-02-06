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
    void dfs(TreeNode* root, int sum, vector<vector<int> >& res, vector<int>& v){
      if(!root){
        return;
      }
      if(!root->left && !root->right){
        if(root->val == sum){
          v.push_back(root->val);
          res.push_back(v);
          v.pop_back();
        }
          return;                
      }

      v.push_back(root->val);
      dfs(root->left, sum-root->val,res,v);
      dfs(root->right, sum-root->val,res,v);
      v.pop_back();

    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> v;
        dfs(root,sum,res,v);
        return res;
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