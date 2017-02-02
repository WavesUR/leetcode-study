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
    ListNode* reverseBetween(ListNode* head, int m, int n) {       
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* cur = head;
        ListNode* prev = newhead;

        for(int i = 1; i<n;i++){
          
          if(i >= m ){
            ListNode* temp = cur -> next;
            cur ->next = temp ->next;
            temp->next = prev -> next;
            prev -> next = temp;
          }else{
            prev = prev -> next;
            cur = cur -> next;
          }
          
        }
        return newhead->next;
    }

};


int main(){

ListNode *head;
head = NULL;

for(int i = 6; i >=0; i--){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}
int m = 1, n = 2;
Solution solution;
head = solution.reverseBetween(head,m,n);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}