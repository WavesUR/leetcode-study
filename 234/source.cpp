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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
          return true;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next && fast->next->next){
          slow = slow -> next;
          fast = fast -> next -> next; 
        }

        ListNode * newhead = slow->next;
        slow -> next = NULL;

        ListNode * curr = newhead;
        ListNode * prev = NULL;
        while(curr){
          ListNode * temp = curr -> next;
          curr->next = prev; 
          prev = curr;
          curr = temp;
        }

        newhead = prev;
        while(newhead){
          if(newhead->val != head->val){
            return false;
          }
          newhead = newhead ->next;
          head = head -> next;
        }
        return true;


    }
};

int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

vector<int> nums;
nums = {1,0,3,4,0,1};

for(int i = 0; i < 6; i++){
  ListNode *node = new ListNode(nums[i]);
  node->next = head;
  head = node;
}

// for(int i = 8; i >=0; i=i-2){
//   ListNode *node = new ListNode(i);
//   node->next = head1;
//   head1 = node;
// }

Solution solution;
bool result = solution.isPalindrome(head);

cout << result << endl;

    
	return 0;
}