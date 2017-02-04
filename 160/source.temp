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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
          return NULL;
        }
        int len_a = 0;
        int len_b = 0;
        ListNode *nodeA = headA, *nodeB = headB;
        while(nodeA){
            nodeA = nodeA->next;
            len_a++;
        }
        while(nodeB){
            nodeB = nodeB->next;
            len_b++;
        }
        nodeA = headA; 
        nodeB = headB;
        if(len_a >= len_b){
          for(int i = 0; i< len_a-len_b;i++){
            nodeA = nodeA->next;
          }
        }else{
          for(int i = 0; i< len_b-len_a;i++){
            nodeB = nodeB->next;
          }
        }
        while(nodeA != NULL){
          if(nodeA == nodeB){
            return nodeA;
          }
          nodeA = nodeA->next;
          nodeB = nodeB->next;
        }
        return NULL;
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

for(int i = 8; i >=0; i=i-1){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
head1 = solution.getIntersectionNode(head,head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
	return 0;
}