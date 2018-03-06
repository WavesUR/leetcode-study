#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
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
    string tree2str(TreeNode* t) {
        if(!t){
            return "";
        }
        string res, left = "", right = "";
        if(t->right){
            right = "(" + tree2str(t->right) + ")";
        }

        if(t->left){
            left = "(" + tree2str(t->left) + ")";
        }else if(t->right){
            left = "()";
        }

        res = to_string(t->val) + left + right;
        return res;
    }
};

int main(){

TreeNode *root = new TreeNode(1);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);
// root->left = root1;
root->right = root2;

string result;

Solution solution;
result = solution.tree2str(root);

cout << result << endl;

    
    return 0;
}