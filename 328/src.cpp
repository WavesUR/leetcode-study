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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
          return NULL;
        }

        ListNode* evenhead = head->next, *eventail = head->next;
        ListNode* oddhead = head, *oddtail = head;

        while(oddtail && oddtail->next && oddtail->next->next){       
          oddtail -> next = oddtail -> next ->next;
          eventail -> next = eventail -> next ->next;
          oddtail = oddtail ->next;
          eventail = eventail -> next;
        }
        
        oddtail -> next = evenhead;
        return oddhead;
    }
};

int main(){

ListNode *head = NULL;
ListNode *result = NULL;

for(int i = 6; i >=0; i--){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

 Solution solution;
 result = solution.oddEvenList(head);
//result = head;

while(result){
  cout << result->val << " ";
  result = result->next;
}
cout << endl;

    
	return 0;
}