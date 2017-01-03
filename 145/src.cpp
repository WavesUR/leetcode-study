#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> proorderTraversal(TreeNode* root) {
      stack<TreeNode*> temp;
      vector<int> result;
        while(root || !temp.empty()){
            while(root){                         
              temp.push(root);
              temp.push(root->right);
              root = root->left;
            }
            root = temp.top();
            temp.pop();
            result.push_back(root->val);
            result.push_back(temp.pop()->val);
            
        }
        return result;
    }
};

int main(){

TreeNode *root = new TreeNode(2);

Solution solution;
root = solution.preorderTraversal(root);

// cout << result << endl;

    
	return 0;
}