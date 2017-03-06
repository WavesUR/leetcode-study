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
#include <unordered_map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    int maxfreq;
    int dfs(TreeNode* root, unordered_map<int,int>& map){
      if(!root){
        return 0;
      }
      int sum = root->val + dfs(root->left,map) + dfs(root->right,map);
      map[sum]++;
      maxfreq = max(maxfreq,map[sum]);
      return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxfreq = 0;
        unordered_map<int,int> map;
        dfs(root,map);
        vector<int> res;
        for(auto m : map){
          if(m.second == maxfreq){
            res.push_back(m.first);
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
vector<int> result = solution.findFrequentTreeSum(root);

 // cout << (long)(INT_MIN - 1) << endl;

    
    return 0;
}