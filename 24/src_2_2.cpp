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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       ListNode* dummy = new ListNode(-1);
       dummy->next = head;
       ListNode* prev = dummy;
       ListNode* cur = dummy->next;
       while(cur && cur->next){
        ListNode * temp = cur->next;
        cur->next = temp->next;
        temp->next = cur;
        prev->next = temp;
        prev = cur;
        cur = cur -> next;
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
head1 = solution.swapPairs(head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
}