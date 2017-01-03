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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root){
          return result;
        }
        stack<TreeNode* > stack1, stack2;
        stack1.push(root);
        while(!stack1.empty() || !stack2.empty()){
          vector<int> temp_v;
          while(!stack1.empty()){
            TreeNode* temp = stack1.top();
            stack1.pop();
            if(temp){
              temp_v.push_back(temp->val);
            }
            if(temp->left){
              stack2.push(temp->left);
            }
            if(temp->right){
              stack2.push(temp->right);
            }
            if(stack1.empty()){
              result.push_back(temp_v);
              temp_v.clear();
            }
          }
          while(!stack2.empty()){
            TreeNode* temp = stack2.top();
            stack2.pop();
            if(temp){
              temp_v.push_back(temp->val);
            }
            if(temp->right){
              stack1.push(temp->right);
            }
            if(temp->left){
              stack1.push(temp->left);
            }
            if(stack2.empty()){
              result.push_back(temp_v);
              temp_v.clear();
            }
          }
        }
        
        return result;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int sum = 3;
vector<vector<int> > result = solution.zigzagLevelOrder(root);

//cout <<to_string(sum) << endl;
// cout << root->val << endl;
    
	return 0;
}