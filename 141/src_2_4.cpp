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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
          if(fast == slow){
            return true;
          }
          slow = slow -> next;
          fast = fast -> next -> next;
        }
        return false;
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

// for(int i = 8; i >=0; i=i-2){
//   ListNode *node = new ListNode(i);
//   node->next = head1;
//   head1 = node;
// }

Solution solution;
bool result = solution.hasCycle(head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << result << endl;

    
	return 0;
}