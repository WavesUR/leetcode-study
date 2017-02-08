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
        vector<vector<int> > res;
        if(!root){
          return res;
        }
        stack<pair<TreeNode*,int> > s1,s2;
        s1.push(pair<TreeNode*,int>(root,1));
        while(!s1.empty() || !s2.empty()){
          while(!s1.empty()){
            auto temp = s1.top();
            s1.pop();
            if(temp.second > res.size()){
              res.push_back({});
            }
            res[temp.second-1].push_back(temp.first->val);
            if(temp.first->left){
              s2.push(pair<TreeNode*,int>(temp.first->left,temp.second+1));
            }
            if(temp.first->right){
              s2.push(pair<TreeNode*,int>(temp.first->right,temp.second+1));
            }
          }
          while(!s2.empty()){
            auto temp = s2.top();
            s2.pop();
            if(temp.second > res.size()){
              res.push_back({});
            }
            res[temp.second-1].push_back(temp.first->val);
            if(temp.first->right){
              s1.push(pair<TreeNode*,int>(temp.first->right,temp.second+1));
            }            
            if(temp.first->left){
              s1.push(pair<TreeNode*,int>(temp.first->left,temp.second+1));
            }
          }
        }

        return res;
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