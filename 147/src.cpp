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
        if(!head){
          return NULL;
        }
        
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        head = newhead;       
        ListNode* cur = head->next;
        ListNode* pre = head;
        
        while(cur->next){
          if(cur->val > cur->next->val){
             while(pre->next->val <= cur->next->val &&pre -> next ){
                  pre = pre -> next;
              }
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next =pre->next;
            pre->next = temp;
            pre = head;
          }else{
            cur = cur->next;
          }
          }         
          
          ListNode* res = head->next;
          delete head;
          return res;
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