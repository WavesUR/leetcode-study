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
    ListNode* partition(ListNode* head, int x) {        
        if(!head){
          return NULL;
        }
        ListNode s_head(0);
        ListNode* s_cur = &s_head;
        ListNode l_head(0);
        ListNode* l_cur = &l_head;
        
        while(head){

          if(head->val < x){
            s_cur-> next = head;
            s_cur= s_cur->next;
            
          }
          else{
            l_cur-> next = head;
            l_cur= l_cur->next;
          }
          head = head -> next;
        }
        l_cur -> next = NULL;
        s_cur -> next = l_head.next;
        return s_head.next;
    }
};


int main(){

ListNode *head;
head = NULL;
int x = 3;

for(int i = 0; i <6; i++){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

Solution solution;
head = solution.partition(head,x);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}