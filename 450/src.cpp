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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;
        TreeNode* cur = root;
        TreeNode* prev = dummy;
        while(cur && cur->val != key){
            if(cur->val > key){
                prev = cur;
                cur = cur->left;
            }else{
                prev = cur;
                cur = cur -> right;
            }
        }
        if(!cur){
            return dummy->left;
        }
        if(!cur->left && !cur->right){
             if(cur == prev->left){
               prev -> left = NULL; 
           }else{
               prev -> right = NULL; 
           }            
            delete cur;
            return dummy->left;
        }else if(cur->left){
            TreeNode * temp = cur -> left;
            while(temp->right){
                temp = temp -> right;
            }
            temp->right = cur -> right;
            if(cur == prev->left){
               prev -> left = cur -> left; 
           }else{
               prev -> right = cur -> left; 
           } 
        }else{
            if(cur == prev->left){
               prev -> left = cur -> right; 
           }else{
               prev -> right = cur -> right; 
           } 

        }
            delete cur;
            return dummy->left;   

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
root = solution.deleteNode(root,3);

// cout << result << endl;

    
    return 0;
}