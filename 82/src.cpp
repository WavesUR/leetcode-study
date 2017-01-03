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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        newhead -> next = head;
        ListNode* cur = newhead -> next;
        ListNode* prev = newhead;
        while(cur){
          if(cur->next && (cur->next->val == cur->val)){ 
              while(cur->next && cur->next->val == cur->val){
                cur = cur ->next;
              }

              prev->next = cur->next;
              cur = cur ->next;

          }else{
            prev = cur;
            cur = cur ->next;
          }

        }
        return newhead->next;
    }
};


int main(){

ListNode *head;
head = NULL;
vector<int> nums;
nums = {2,2,1,1,1};
for(int i = 0; i <nums.size(); i++){
  ListNode *node = new ListNode(nums[i]);
  node->next = head;
  head = node;
}
Solution solution;
head = solution.deleteDuplicates(head);

while(head){
  cout << head->val << " ";
  head = head->next;
}

cout << endl;

    
	return 0;
}