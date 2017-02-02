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

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL){
//           return NULL;
//         }
//         ListNode *current = head, *prev = NULL;
//         while(current != NULL){
//           ListNode *newnode = current->next;
//           current->next = prev;
//           prev = current;
//           current = newnode;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
          return NULL;
        }
        return reverseList(head, NULL);
    }

    ListNode* reverseList(ListNode* current, ListNode* prev) {
        if(current->next == NULL){
 //         ListNode *newnode = current->next; // will be delete when exit loop
          current->next = prev;
          return current;
        }else{
          ListNode* result = reverseList(current->next, current);
          current->next = prev;
          return result;
        }
        
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