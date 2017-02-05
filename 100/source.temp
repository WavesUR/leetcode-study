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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
          return true;
        }      
        if(!p || !q){
          return false;
        }
        if(p->val == q->val){
          return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }else{
          return false;
        }

    }
};
int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);

Solution solution;
bool result = solution.isSameTree(root,root1);

cout << result << endl;

    
	return 0;
}