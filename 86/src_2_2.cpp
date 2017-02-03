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
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* cur1 = dummy1;
        ListNode* cur2 = dummy2;
        while(head){
          if(head->val < x){
            cur1->next = head;
            cur1 = cur1->next;
          }else{
            cur2->next = head;
            cur2 = cur2->next;
          }
          head = head->next;
        }
        cur2->next = NULL;
        cur1->next = dummy2->next;

        return dummy1->next;
    }
};


int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

vector<int> v1 = {1,4,3,10,5,9,7};

for(int i = v1.size()-1; i >= 0; i--){
  ListNode *node = new ListNode(v1[i]);
  node->next = head;
  head = node;
}

Solution solution;
head1 = solution.partition(head,2);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}

cout << endl;

    
	return 0;
}