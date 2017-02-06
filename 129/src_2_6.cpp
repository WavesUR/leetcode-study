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
    void dfs(TreeNode* root, int& sum, int& cur_sum){
      if(!root){
        return;
      }
      if(!root->left && !root->right){
        int temp = root->val + cur_sum * 10;
        sum = sum + temp;
        return;
      }
      int temp = cur_sum * 10 + root->val;
      dfs(root->left,sum,temp);
      dfs(root->right,sum,temp);

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int cur_sum = 0;
        dfs(root,sum,cur_sum);
        return sum;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
int result = solution.sumNumbers(root);

cout << result << endl;

    
	return 0;
}