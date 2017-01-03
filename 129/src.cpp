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
    int sumNumbers(TreeNode* root) {
         if(!root){
        return 0;
        }
        int sum = 0;
        helper(root, root->val, sum);
        return sum;
    }
    void helper(TreeNode* root, int current, int& sum){

      if(!root->left && !root->right){
        sum += current;
        return;
      }
      if(root->left) {
        helper(root->left,current*10+root->left->val, sum);
      } 
      if(root->right) {
        helper(root->right,current*10+root->right->val, sum);
      } 
      return;
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