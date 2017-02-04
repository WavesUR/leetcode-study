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

// time: O(max(m,n))
// space: O(max(m,n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> val1, val2;
        int c = 0;
        while(l1){
          val1.push_back(l1->val);
          l1 = l1 -> next;
        }
        while(l2){
          val2.push_back(l2->val);
          l2 = l2 -> next;
        }
        int i = val1.size()-1, j = val2.size()-1;
        ListNode* tail = NULL;
        while(i >= 0 || j >= 0 || c != 0){
          int op1 = i >= 0 ? val1[i] : 0;
          int op2 = j >= 0 ? val2[j] : 0;
          int sum = op1 + op2 + c;
          ListNode* node = new ListNode(sum%10);
          c = sum >= 10? 1 : 0;
          node->next = tail;
          tail = node;
          i--;
          j--;
        }
        return tail;
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

for(int i = 8; i >=0; i=i-2){
  ListNode *node = new ListNode(i);
  node->next = head1;
  head1 = node;
}

Solution solution;
head1 = solution.addTwoNumbers(head,head1);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
    return 0;
}