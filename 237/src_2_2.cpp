#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Time: O(1)
// Space: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL){
          return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
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
solution.deleteNode(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}
cout << endl;

    
	return 0;
}