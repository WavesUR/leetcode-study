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

// Time: O(n) 
class Solution {
public:
    void count_node(TreeNode* root, int& k, int& res){
      if(!root || k == 0){
        return;
      }
      count_node(root->left,k,res);
      if(k == 1){
          res = root->val;
          k--;
      }else{
        k--;
      }
      count_node(root->right,k,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res; 
        count_node(root,k,res);
        return res;
    }
};

int main(){

TreeNode *root = new TreeNode(2);
int k = 3;
Solution solution;
int result = solution.kthSmallest(root, k);

// cout << result << endl;

    
  return 0;
}