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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* cur = head;
        while(cur){
          if(cur-> next && cur->next ->val < cur->val){
            ListNode* prev = dummy;
            while(prev ->next && prev->next->val < cur->next->val){
              prev = prev -> next;
            }
          ListNode* node = prev->next;
          ListNode* node2 = cur->next;
          cur->next = node2 ->next;
          prev->next = node2;
          node2 -> next = node;               
          }
          else{
            cur = cur ->next;
          }
        }
        return dummy->next;
    }
};


int main(){

ListNode *head;
head = NULL;

for(int i = 0; i <6; i++){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

Solution solution;
head = solution.insertionSortList(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}