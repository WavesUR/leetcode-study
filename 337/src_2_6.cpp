#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
// #include <utility> 
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> dfs(TreeNode* root){
      if(!root){
        return {0,0}; // {[i], [i-1]}
      }
      vector<int> l = dfs(root->left);
      vector<int> r = dfs(root->right);
      return {max(root->val + l[1] + r[1], l[0] + r[0]),l[0]+r[0]};
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return res[0];
    }
};

int main(){
TreeNode *root = new TreeNode(2);
vector<vector<int> > output;

Solution solution;
int res = solution.rob(root);

// cout << result << endl;

    
	return 0;
}