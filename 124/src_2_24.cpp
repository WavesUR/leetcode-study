#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
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
    int maxsum;
    int dfs(TreeNode* root){
        if(!root){
          return 0;
        }
        int leftsum = dfs(root->left);
        int rightsum = dfs(root->right);        
        int sum3 = leftsum + root->val + rightsum;
        int sum2 = root->val + max(leftsum,rightsum);
        int max2 = max(sum2,root->val);
        maxsum = max(maxsum,max(max2,sum3));
        
        return max2;
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        int temp = dfs(root);
        return maxsum;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
int result = solution.maxPathSum(root);

cout << result << endl;

    
	return 0;
}