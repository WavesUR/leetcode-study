#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    int min_val;
    int prev = -1;
    void dfs(TreeNode* root){
        if(!root){
          return;
        }
        dfs(root->left);
        if(prev != -1){
          min_val = min(min_val, abs(root->val - prev)); 
        }
        prev = root -> val;  
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        min_val = INT_MAX;
        dfs(root);
        return min_val;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

vector<vector<int> > input;


Solution solution;
int result = solution.getMinimumDifference(root);

cout << result << endl;

    
    return 0;
}