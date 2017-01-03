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
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }


    ListNode* mergesort(ListNode* head){
      if(!head){
        return NULL;
      }
      
      if(head -> next == NULL){
        return head;
      }

      ListNode* pre = head;
      ListNode* cur_s = head;
      ListNode* cur_f = head;

      while(cur_f && cur_f->next){
        pre = cur_s;
        cur_s = cur_s -> next;
        cur_f = cur_f -> next -> next;
       
      }
      pre -> next = NULL; // important
      return merge(mergesort(head), mergesort(cur_s));
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
      if(!head1) return head2;
      if(!head2) return head1;
      ListNode * head = NULL;     
      head = (head1 -> val <= head2 -> val) ? head1 : head2;
      head->next = merge(head->next, head1->val <= head2->val ? head2 : head1);
      return head;
    }
};


int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

for(int i = 5; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

for(int i = 8; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
ListNode * head2 = solution.sortList(head);
//ListNode * head2 = solution.merge(head, head1);

while(head2){
  cout << head2->val << " ";
  head2 = head2->next;
}
cout << endl;

    
    return 0;
}