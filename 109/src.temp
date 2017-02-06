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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
          return NULL;
        }

        return helper(head, NULL);
    }
    TreeNode* helper(ListNode* start, ListNode* last){
        if(start == last){
          return NULL;
        }
        ListNode *node_fast = start;
        ListNode *node_slow = start;
        while(node_fast != last && node_fast->next != last){
          node_fast = node_fast->next->next;
          node_slow = node_slow->next;
        }
        TreeNode* treehead = new TreeNode(node_slow->val);
        cout << treehead->val << endl;
        treehead->left = helper(start, node_slow); 
        treehead->right = helper(node_slow->next, last); 
        return treehead;
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