#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int start, int end, int i, unordered_map<int,int>& my_map){
        if(start > end || i >= preorder.size()){
          return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i]);
        int pos = my_map[preorder[i]];
        node->left = dfs(preorder,inorder,start,pos-1,i+1,my_map);
        node->right = dfs(preorder,inorder,pos+1,end,pos-start + i + 1,my_map);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int> my_map;
       for(int i = 0; i < inorder.size(); i++){
          my_map[inorder[i]] = i;
       } 
       int i = 0;
       return dfs(preorder,inorder,0,preorder.size()-1,i,my_map);

    }
};
int main(){

vector<int> inorder = {2,1};
vector<int> preorder = {1,2};
// for(int i = 8; i >=0; i=i-2){
//   ListNode *node = new ListNode(i);
//   node->next = head1;
//   head1 = node;
// }

Solution solution;
TreeNode* result = solution.buildTree(preorder,inorder);

// while(head1){
//   cout << head1->val << " ";
//   head1 = head1->next;
// }
// cout << result << endl;

    
	return 0;
}