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

//Time: O(nlogn)
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2){
      if(!head1){
        return head2;
      }
      if(!head2){
        return head1;
      }
      ListNode* head = head1->val > head2->val ? head2 : head1;
      head->next = merge(head->next, head1->val > head2->val ? head1: head2);
      return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head){
          return NULL;
        }
        if(!head->next){
          return head;
        }
        if(!head->next->next){
          if(head->val < head->next->val){
            return head;
          }else{
            ListNode * temp = head -> next;
            head -> next = NULL;
            temp->next = head;
            return temp;
          }
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
          fast = fast -> next -> next;
          slow = slow -> next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        return merge(sortList(head),sortList(head2));


    }
};


int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

vector<int> v1 = {1,4,3,10,5,9,7};
// vector<int> v2 = {2,4,6,8,10};

for(int i = 0; i < v1.size(); i++){
  ListNode *node = new ListNode(v1[i]);
  node->next = head;
  head = node;
}

// for(int i = 0; i < v2.size(); i++){
//   ListNode *node = new ListNode(v2[i]);
//   node->next = head1;
//   head1 = node;
// }

Solution solution;
head1 = solution.sortList(head);

while(head1){
  cout << head1->val << " ";
  head1 = head1->next;
}
cout << endl;

    
    return 0;
  
}