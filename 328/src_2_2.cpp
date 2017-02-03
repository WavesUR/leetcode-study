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
        ListNode* dummy_o = new ListNode(-1);
        ListNode* dummy_e = new ListNode(-1);
        ListNode* cur_o = dummy_o;
        ListNode* cur_e = dummy_e;
        bool flag = true; // odd
        while(head){
          if(flag){
            cur_o->next = head;
            cur_o = cur_o ->next;
            flag = !flag;
          }else{
            cur_e->next = head;
            cur_e = cur_e ->next;
            flag = !flag;           
          }
          head = head -> next;
        }
        cur_e -> next = NULL;
        cur_o -> next = dummy_e -> next;
        return dummy_o->next;
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
// result = head;

while(result){
  cout << result->val << " ";
  result = result->next;
}
cout << endl;

    
	return 0;
}