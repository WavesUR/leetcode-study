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
//recursive
//Time: O(n) 
// class Solution {
// public:
//     bool dfs(TreeNode* p, TreeNode* q){
//       if(!p && !q){
//         return true;
//       }
//       if(!p || !q){
//         return false;
//       }
//       if(p->val != q->val){
//         return false;
//       }

//       return dfs(p->left,q->right) && dfs(p->right,q->left);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(!root){
//           return true;
//         }
//         return dfs(root->left,root->right);
//     }
// };

//iterative
//Time: O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
          return true;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(root);
        while(!Q.empty()){
          TreeNode* temp1 = Q.front();
          Q.pop();
          TreeNode* temp2 = Q.front();
          Q.pop();
          if(!temp1 && !temp2){
            continue;
          }
          if(!temp1 || !temp2){
            return false;
          }
          if(temp1->val != temp2->val){
            return false;
          }
          Q.push(temp1->left);
          Q.push(temp2->right);
          Q.push(temp1->right);
          Q.push(temp2->left);         
        }
        return true;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
bool result = solution.isSymmetric(root);

cout << result << endl;

    
	return 0;
}