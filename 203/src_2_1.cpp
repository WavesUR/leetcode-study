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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* node = dummy;
        while(node ->next){
          if(node->next->val == val){
            ListNode* temp = node->next;
            node ->next = node ->next->next;
            delete temp;
          }else{
            node = node->next;
          }         
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

for(int i = 8; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
ListNode* result = solution.removeElements(head1,3);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << result << endl;

    
	return 0;
}