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
    unordered_map<int,int> mymap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
          return NULL;
        }
        int len = inorder.size();
        for(int i = 0; i < len;i++){
          mymap[inorder[i]] = i;
        }
       return helper(inorder,preorder,0,len-1,0,len-1);

    }
    TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int in_s, int in_e, int pre_s, int pre_e){
        if(in_s > in_e || pre_s > pre_e){
          return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pre_s]);
        int mid = mymap[preorder[pre_s]];
        int num = mid - in_s;
        root->left = helper(inorder, preorder,in_s,mid - 1, pre_s + 1,pre_s + num);
        root->right = helper(inorder, preorder, mid + 1, in_e, pre_s + num + 1,pre_e);

        return root;
    }
};

int main(){

vector<int> inorder = {4,2,5,1,6,3,7};
vector<int> preorder = {1,2,4,5,3,6,7};
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