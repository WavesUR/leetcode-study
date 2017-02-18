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

//max-heap: 
//time: O(n) + O(nlogn) + O(klogn)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> res;
//         unordered_map<int,int> my_map;
//         for(int i = 0; i < nums.size(); i++){
//           my_map[nums[i]]++;
//         }
//         priority_queue<pair<int,int> > my_q;
//         for(auto map : my_map){
//           my_q.push(make_pair(map.second,map.first));
//         }
//         for(int i = k; i >0;i--){
//           auto temp = my_q.top();
//           res.push_back(temp.second);
//           my_q.pop();
//         }
//         return res;
//     }
// };

//bucket sort
//Time: O(n)
//Space: O() ?
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> my_map;
        for(int i = 0; i < nums.size(); i++){
          my_map[nums[i]]++;
        }
        vector<vector<int> > bucket(nums.size()+1);
        for(auto map:my_map){
          bucket[map.second].push_back(map.first);
        }
        for(int i = nums.size();i >= 0 && k > 0; i--){
          if(bucket[i].size() != 0){
            for(int j = 0; j < bucket[i].size();j++){
              res.push_back(bucket[i][j]);
              k--;
          }
          }
        }
        return res;
    }
};


int main(){

  vector<int> nums;
  nums = {1,2};
  int k = 2;
   Solution solution;
   vector<int> result = solution.topKFrequent(nums, k);
 for(int i = 0; i < result.size();i++){
    cout << result[i] << endl;
 }


    
  return 0;
}