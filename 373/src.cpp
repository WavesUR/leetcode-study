#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
#include <queue>          // std::priority_queue
using namespace std;

// Time: O(klogk)
class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int> > res;
        if(nums1.empty() || nums2.empty()){
          return res;
        }
        auto comp = [&nums1,&nums2](pair<int,int>& a, pair<int,int>& b){return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];};
        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(comp)> minheap(comp);
        int count = k;
        for(int i = 0; i < min(k,(int)nums1.size()); i++){
          minheap.push(make_pair(i,0));
        }
        while(k > 0 && !minheap.empty()){
              auto temp = minheap.top();
              res.push_back(make_pair(nums1[temp.first],nums2[temp.second]));
              minheap.pop(); 
              if(temp.second + 1 < nums2.size()){
                minheap.push(make_pair(temp.first,temp.second+1));   
              }                                     
              k--;          
        }
        return res;
    }
};
int main(){

  vector<int> nums1,nums2;
  nums1 = {1,1,2};
  nums2 = {1,2,3};
  int k = 1;
   Solution solution;
   vector<pair<int, int> > result = solution.kSmallestPairs(nums1, nums2,10);
 for(int i = 0; i < result.size();i++){
    cout << result[i].first << " " << result[i].second << endl;
 }


    
  return 0;
}