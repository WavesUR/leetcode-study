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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root){
          return res;
        }
        queue<pair<TreeNode*,int> > Q;
        Q.push(pair<TreeNode*,int>(root,1));
        while(!Q.empty()){
          auto temp = Q.front();
          Q.pop();
          if(temp.second > res.size()){
            res.push_back({});
          }
          res[temp.second-1].push_back(temp.first->val);
          if(temp.first->left){
            Q.push(pair<TreeNode*,int>(temp.first->left,temp.second+1));
          }
          if(temp.first->right){
            Q.push(pair<TreeNode*,int>(temp.first->right,temp.second+1));
          }
        }
        return res;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

vector<vector<int> > input;
vector<vector<int> > result;

Solution solution;
result = solution.levelOrder(root);

// cout << result << endl;

    
	return 0;
}