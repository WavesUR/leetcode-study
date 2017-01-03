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

        if(head == NULL){
          return head;
        }
        
        if(head != NULL && head->next != NULL){
          ListNode * rightnode = head->next;
          head -> next = swapPairs(rightnode->next); 
          rightnode->next = head;
          return rightnode;
        }else{
          return head;
        }
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