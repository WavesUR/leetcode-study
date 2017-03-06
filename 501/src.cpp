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
    int maxfreq = 0;
    long prev;
    void findfreq(TreeNode* root, int freq){
      if(!root){
        return;
      }
      findfreq(root->left,freq);
      if(root->val != prev){
        freq = 1;
      }else{
        freq++;
      }
      maxfreq = max(freq,maxfreq);
      prev = root->val;
      findfreq(root->right,freq);
    }
    void recordmode(TreeNode* root, vector<int>& res, int freq){
      if(!root){
        return;
      }
      recordmode(root->left, res,freq);
      if(root->val != prev){
        freq = 1;
      }else{
        freq++;
      }
        if(freq == maxfreq){
          res.push_back(root->val);
        }      
      prev = root -> val;
      recordmode(root->right,res,freq);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int freq = 0;
        prev = (long)(INT_MIN) - 1;
        findfreq(root, freq);
        prev = (long)INT_MIN - 1;
        recordmode(root, res, freq);  
        return res;      
    }
};

int main(){

TreeNode *root = new TreeNode(2);
TreeNode *root1 = new TreeNode(2);
TreeNode *root2 = new TreeNode(3);

vector<vector<int> > input;


Solution solution;
//vector<int> result = solution.findMode(root);

 cout << (long)(INT_MIN - 1) << endl;

    
    return 0;
}