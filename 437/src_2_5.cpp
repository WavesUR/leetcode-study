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
    int dfs(TreeNode* root,  int res){
      if(!root){
        return 0;
      }
      int count = 0;
      if(root->val == res){
        count++;
      }
      count = count + dfs(root->right,res-root->val) + dfs(root->left,res-root->val);
      return count;

    }
    int pathSum(TreeNode* root, int sum) {
        int count = 0; 
        if(!root){
          return 0;
        }
        count = dfs(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
        return count;
    }
};
int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
bool result = solution.pathSum(root,sum);

cout << result << endl;

    
	return 0;
}