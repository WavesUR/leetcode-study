#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root){
          return v;
        }
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,1));
        int level = 0;
        while(!q.empty()){
          auto temp = q.front();
          q.pop();
          if(temp.second != level){
            v.push_back(temp.first->val);
            level = temp.second;
          }
          if(temp.first->right){
            q.push(make_pair(temp.first->right,temp.second+1));
          }
          if(temp.first->left){
            q.push(make_pair(temp.first->left,temp.second+1));
          }
          
        }
        return v;
    }
};

int main(){

  vector<int> result;
  TreeNode* root;
  Solution solution;
  result = solution.rightSideView(root);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  // cout << result << endl;


    
  return 0;
}