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
        int count = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 0; i < m - 1; i++){
          pre = pre->next;
        }
        ListNode* cur = pre -> next;
        for(int i = m; i < n; i++){
          ListNode* move = cur -> next;
          cur -> next = move -> next;
          move -> next = pre -> next;
          pre ->next = move;
        }

        return dummy->next;
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
int m = 2, n = 4;
Solution solution;
head = solution.reverseBetween(head,m,n);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}