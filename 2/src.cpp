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

// time: O(max(m,n))
// space: O(max(m,n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1 || l2 || c != 0){
          int val1 = (l1 != NULL ? l1->val : 0);
          int val2 = (l2 != NULL ? l2->val : 0); 
          int sum = val1 + val2 + c;
          
          ListNode*  newnode = new ListNode(sum%10);
          c = (sum >= 10) ? 1 : 0;
          cur->next = newnode;
          cur = cur ->next;
          l1 = l1 ? l1->next : NULL;
          l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
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
head1 = solution.addTwoNumbers(head,head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
}