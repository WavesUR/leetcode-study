#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Time: O(nklogk)
// class Solution {
// public:
//     ListNode* merge(ListNode* head1, ListNode* head2){
//         if(head1 && head2){
//           ListNode * node = head1->val < head2 -> val ? head1 : head2;
//           node -> next = merge(node->next, head1->val < head2->val ? head2 : head1);
//           return node; 
//         }else if(head1){
//           return head1;
//         }else if(head2){
//           return head2;
//         }else{
//           return NULL;
//         }
//     }
//     ListNode* helper(vector<ListNode*>& lists, int start, int end) {
//         if(start == end){
//           return lists[start];
//         }
//         if(start == end - 1){
//           return merge(lists[start],lists[end]);
//         }
//         int mid = start + (end - start)/2;
//         return merge(helper(lists,start,mid),helper(lists,mid+1,end));
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.empty()){
//           return NULL;
//         }
//         return helper(lists,0,lists.size() - 1);
//     }
// };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(int i = 0; i < lists.size(); i++){
          if(lists[i]){
            pq.push(lists[i]);
          }
        }
        if(pq.empty()){
          return NULL;
        }
        ListNode* res = pq.top();
        pq.pop();
        if(res->next){
          pq.push(res->next);
        }
        ListNode* tail = res;
        while(!pq.empty()){
          tail->next = pq.top();
          tail = tail -> next;
          pq.pop();
          if(tail->next){
          pq.push(tail->next);
        }
        }
        return res;
    }
};

int main(){

ListNode *head = NULL;
ListNode *head1 = NULL;

vector<ListNode*> lists;

Solution solution;
head1 = solution.mergeKLists(lists);

// while(head1){
//   cout << head1->val << " ";
//   head1 = head1->next;
// }
// cout << endl;

    
	return 0;
}