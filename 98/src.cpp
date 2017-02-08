
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#include <climits>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool check(TreeNode* root, long right_upper, long left_lower){
		if(!root){
    		return true;
    	}
    	return (root->val>left_lower && root->val<right_upper && check(root->left,root->val,left_lower) && check(root->right,right_upper,root->val));

	}
    bool isValidBST(TreeNode* root) {
        return check(root,(long)INT_MAX-1,(long)INT_MIN+1);
    }
};

int main(){
TreeNode *root = new TreeNode(2);

Solution solution;
bool output = solution.isValidBST(root);

// cout << result << endl;

    
	return 0;
}