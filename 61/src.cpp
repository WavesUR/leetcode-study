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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
          return NULL;
        }
        ListNode* fast = head;
        int count = 0;
        while(fast->next){
          count++;
          fast = fast->next;
        }
        k = k % (count + 1);
        cout << count + 1 << endl;
        fast -> next = head;
        ListNode* slow = head;
        while(count > k){
          slow = slow -> next;
          count--;
        }
        ListNode* newhead = slow->next;
        slow->next = NULL;
        return newhead;

    }
};

int main(){

ListNode *head;
head = NULL;

vector<int> v = {6,5,4,3,2,1,0};

for(int i = 0; i <= v.size(); i++){
  ListNode *node = new ListNode(v[i]);
  node->next = head;
  head = node;
}
Solution solution;
head = solution.rotateRight(head,3);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}