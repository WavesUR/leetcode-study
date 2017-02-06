#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL){
//           return NULL;
//         }
//         ListNode *current = head, *prev = NULL;
//         while(current != NULL){
//           ListNode *newnode = current->next;
//           current->next = prev;
//           prev = current;
//           current = newnode;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    TreeNode* dfs(ListNode* start, ListNode* end){
        if(start == end){
          return NULL;
        }
        ListNode* fast = start;
        ListNode* slow = start;

        while(fast != end && fast->next != end){
          fast = fast->next->next;
          slow = slow -> next;
        }
        TreeNode* node = new TreeNode(slow -> val);        
        node->left = dfs(start,slow);
        node->right = dfs(slow->next,end);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* tree_head = dfs(head,NULL);
        return tree_head;
    }
};


int main(){

ListNode *head;
head = NULL;
TreeNode *treehead;

for(int i = 5; i >=0; i--){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

Solution solution;
treehead = solution.sortedListToBST(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}