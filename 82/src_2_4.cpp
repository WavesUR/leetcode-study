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
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* cur = dummy;
        ListNode* fast = head;
        while(fast){
          ListNode* next = fast->next;
          if(next && fast->val == next ->val){
            while(next && fast->val == next->val){
              next = next -> next;
            }
            fast = next;
            cur->next = fast;
          }else{
            cur->next = fast;
            cur = cur -> next;
            fast = fast -> next;
          }
        }
        return dummy->next;
    }
};


int main(){

ListNode *head;
head = NULL;
vector<int> nums;
nums = {3,2,2,1,1,1};
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