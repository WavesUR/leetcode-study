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
    vector<TreeNode*> generateTrees(int n) {
      
      return helper(1,n);
    }
    vector<TreeNode*> helper(int start, int last){
      vector<TreeNode*> result;
      if(start > last){
        result.push_back(NULL);
        return result;
      }
      if(start == last){
        result.push_back(new TreeNode(start));
        return result;
      }

      for(int i = start; i<=last; i++){
         vector<TreeNode*> l = helper(start, i-1);
         vector<TreeNode*> r = helper(i+1, last);
         for(int j = 0; j < l.size();j++){
          for(int k = 0; k < r.size();k++){
            TreeNode * n = new TreeNode(i);
            n->left = l[j];
            n->right = r[k];
            result.push_back(n);
          }
         }
      }
      return result;
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