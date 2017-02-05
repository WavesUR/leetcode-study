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

// Time: O(L)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = n + 1;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(count && fast){
          fast = fast -> next;
          count--;
        }
        while(fast){
          fast = fast -> next;
          slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow->next  = slow->next->next;
        delete temp;
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

for(int i = 1; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
head1 = solution.removeNthFromEnd(head1,2);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
}