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
    void deleteNode(ListNode* node) {
      if(node  == NULL)
        return;
      if(node->next == NULL)
        return;
      ListNode *nextNode = node->next;
        node->val = node -> next ->val;
        node->next = node ->next -> next;
      delete nextNode;
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