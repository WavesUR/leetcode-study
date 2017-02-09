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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int start, int end, int i, unordered_map<int,int>& my_map){
      if(start > end){
        return NULL;
      }

      TreeNode* node = new TreeNode(postorder[i]);
      int pos = my_map[postorder[i]];
      node->right = dfs(inorder,postorder,pos+1,end,i-1,my_map);
      node->left = dfs(inorder,postorder,start,pos-1,i-(end-pos)-1,my_map);
      return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int> my_map; 
       for(int i =0;i < inorder.size();i++){
        my_map[inorder[i]] = i;
       }
       return dfs(inorder,postorder,0,inorder.size()-1,postorder.size()-1,my_map);
    }
};

int main(){

vector<int> inorder = {4,2,5,1,6,3,7};
vector<int> postorder = {4,5,2,6,7,3,1};
// for(int i = 8; i >=0; i=i-2){
//   ListNode *node = new ListNode(i);
//   node->next = head1;
//   head1 = node;
// }

Solution solution;
TreeNode* result = solution.buildTree(inorder, postorder);

// while(head1){
//   cout << head1->val << " ";
//   head1 = head1->next;
// }
// cout << result << endl;

    
	return 0;
}