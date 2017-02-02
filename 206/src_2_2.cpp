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

//iterative
//Time: O(n)
// Space: O(1)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* cur = head;
//         ListNode* prev = NULL;
//         while(cur){
//           ListNode* temp = cur->next;
//           cur->next = prev;
//           prev = cur;
//           cur = temp;
//         }
//         return prev;
//     }
// };
// Recursive
// Time: O(n)
// Space: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
          return head;
        }
        ListNode* tail = head->next;
        head->next = NULL;
        ListNode* newhead = reverseList(tail);
        tail->next = head;

        return newhead;
    }
};

int main(){

ListNode *head = NULL;

for(int i = 0; i < 5; i++){
  ListNode *node = new ListNode(i);
  node->next = head;
  head = node;
}

Solution solution;
head = solution.reverseList(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}
cout << endl;

    
	return 0;
}