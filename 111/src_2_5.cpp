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
    int minDepth(TreeNode* root) {
        if(!root){
        	return 0;
        }
        queue<pair<TreeNode*,int> > Q;
        Q.push(pair<TreeNode*,int>(root,1));
        while(!Q.empty()){
        	auto temp = Q.front();
        	Q.pop();
        	TreeNode* cur = temp.first;
        	if(!cur->left && !cur->right){
        		return temp.second;
        	}
        	if(cur->left){
        		Q.push(pair<TreeNode*,int>(cur->left,temp.second + 1));
        	}
         	if(cur->right){
        		Q.push(pair<TreeNode*,int>(cur->right,temp.second + 1));
        	}       	
        }
        return -1;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

Solution solution;
int result = solution.minDepth(root);

cout << result << endl;

    
	return 0;
}