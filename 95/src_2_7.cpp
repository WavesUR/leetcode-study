#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
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
    vector<TreeNode*> dp(int start, int end){
      vector<TreeNode*> res;
      if(start > end){
        res.push_back(NULL);
        return res;
      }
      if(start == end){
        TreeNode* node = new TreeNode(start);
        res.push_back(node);
        return res;
      }
      for(int i = start; i<=end; i++){
        vector<TreeNode*> left_sub = dp(start,i-1);
        vector<TreeNode*> right_sub = dp(i+1,end);
        for(int j = 0; j < left_sub.size();j++){
          for(int k = 0; k < right_sub.size();k++){
             TreeNode* root = new TreeNode(i);
            root->left = left_sub[j];
            root->right = right_sub[k];
            res.push_back(root);
          }
        }
      }
      return res;
    }
    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode*> res;
      if(n<=0){
        return res;
      }
      return dp(1,n);
    }
};

int main(){

  int n = 3;
  Solution solution;
  vector<TreeNode*> result = solution.generateTrees(n);
  // for(int i = 0; i < result.size(); i++){
  //   for(int j = 0; j < result[0].size();j++){
  //     cout << result[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  


    
  return 0;
}