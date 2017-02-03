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

//iterative
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(-1);
//         ListNode* cur1 = l1;
//         ListNode* cur2 = l2;
//         ListNode* cur3 = dummy;
//         while(cur1 && cur2){
//           if(cur1->val <= cur2->val){
//             cur3->next = cur1;
//             cur1 = cur1 -> next;
//           }else{
//             cur3->next = cur2;
//             cur2 = cur2 -> next;
//           }
//           cur3 = cur3 -> next;
//         }
//         if(cur1){
//           cur3->next = cur1;
//         }else{
//           cur3->next = cur2;
//         }
//         return dummy->next;
//     }
// };

//recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
          return l2;
        }
        if(!l2){
          return l1;
        }
        ListNode* head;
        head = l1->val > l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, l1->val > l2->val ? l1:l2);
        return head;
    }
};

int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

for(int i = 5; i >=0; i=i-2){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

for(int i = 8; i >=0; i=i-2){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
head1 = solution.mergeTwoLists(head, head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
  
}