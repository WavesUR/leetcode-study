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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> n;
        if(!root){
            return res;
        }
        queue<pair<TreeNode*, int> > Q;
        Q.push(pair<TreeNode*, int>(root,1));
        while(!Q.empty()){
            auto temp = Q.front();
            Q.pop();
            if(res.size() < temp.second){
                res.push_back(0);
                n.push_back(0);
            }
            res[temp.second - 1] += temp.first->val;
            n[temp.second - 1]++;
            if (temp.first->left){
                Q.push(pair<TreeNode*, int>(temp.first->left, temp.second + 1));
            }
            if (temp.first->right){
                Q.push(pair<TreeNode*, int>(temp.first->right, temp.second + 1));
            }
        }

        for(int i = 0; i < res.size(); i++){
            res[i] = res[i]/n[i];
        }

        return res;

    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);
root->left = root1;
root->right = root2;

vector<double > result;

Solution solution;
result = solution.averageOfLevels(root);

for(int i = 0; i < result.size(); i++){
    cout << result[i] << endl;
}

    
	return 0;
}