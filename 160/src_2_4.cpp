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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = 0, len_b = 0;
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        while(cur_a){
          len_a++;
          cur_a = cur_a ->next;
        }
        while(cur_b){
          len_b++;
          cur_b = cur_b -> next;
        }
        if(!cur_a || !cur_b){
          return NULL;
        }
        cur_a = headA;
        cur_b = headB;
        if(len_a > len_b){
          while(len_a != len_b){
            cur_a = cur_a -> next;
            len_a--;
          }
        }else if(len_a < len_b){
          while(len_a != len_b){
            cur_b = cur_b -> next;
            len_b--;
          }
        }
        while(cur_a && cur_b){
          if(cur_a == cur_b){
            return cur_a;
          }else{
            cur_b = cur_b -> next;
            cur_a = cur_a -> next;
          }
        }
        return NULL;
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

for(int i = 8; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
head1 = solution.getIntersectionNode(head,head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
}