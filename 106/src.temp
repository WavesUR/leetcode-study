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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()){
          return NULL;
        }
        int len = inorder.size();
        for(int i = 0; i < len;i++){
          mymap[inorder[i]] = i;
        }
       return helper(inorder, postorder,0,len-1,0,len-1);

    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int post_s, int post_e){
        if(in_s > in_e || post_s > post_e){
          return NULL;
        }

        TreeNode* root = new TreeNode(postorder[post_e]);
        int mid = mymap[postorder[post_e]];
        int num = mid - in_s;
        root->left = helper(inorder, postorder,in_s,mid - 1, post_s,post_s + num - 1);
        root->right = helper(inorder, postorder, mid + 1, in_e, post_s + num,post_e - 1);

        return root;
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