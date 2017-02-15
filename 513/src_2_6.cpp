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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        int level_flag = 0;
        queue<pair<TreeNode*,int> > my_q;
        my_q.push(make_pair(root,1));
        while(!my_q.empty()){
          auto temp = my_q.front();
          my_q.pop();
          TreeNode* node = temp.first;
          int level = temp.second;
          if(level != level_flag){
            res = node->val;
            level_flag = level;
          }
          if(node->left){
            my_q.push(make_pair(node->left,level+1));
          }
          if(node->right){
            my_q.push(make_pair(node->right,level+1));            
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


Solution solution;
int result = solution.findBottomLeftValue(root);

// cout << result << endl;

    
	return 0;
}