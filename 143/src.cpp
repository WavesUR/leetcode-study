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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
          return;
        }
        // find the middle point
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast && fast->next){
          fast = fast -> next ->next;
          slow = slow -> next;
        }
        // make second half list to be new list
        ListNode * head2 = slow->next;
        slow -> next = NULL;
        ListNode * cur = head2 -> next;
        head2 -> next = NULL;
        // recurse the second halp list
        while(cur){
          ListNode * temp = cur -> next;
          cur -> next = head2;          
          head2 = cur;
          cur = temp;
        }
        // merge two list
        fast = head;
        slow = head2;
        while(fast && slow){
          ListNode * temp = slow -> next;
          slow -> next = fast -> next;
          fast -> next = slow;
          fast = slow -> next;
          slow = temp; 
        }
    }
};

int main(){

ListNode *head;
head = NULL;

vector<int> v = {7,6,5,4,3,2,1};

for(int i = 0; i <= v.size(); i++){
  ListNode *node = new ListNode(v[i]);
  node->next = head;
  head = node;
}
Solution solution;
solution.reorderList(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}