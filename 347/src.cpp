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

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size();i++){
            mymap[nums[i]]++;
        }
        priority_queue<pair<int, int> > maxHeap;
        for(auto & pair: mymap){
            maxHeap.emplace(pair.second, pair.first);
        }
        vector<int> result;
        while(k){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return result;
    }
};
int main(){

  vector<int> nums;
  nums = {1,1,1,2,2,3};
  int k = 1;
   Solution solution;
   vector<int> result = solution.topKFrequent(nums, k);
 for(int i = 0; i < result.size();i++){
    cout << result[i] << endl;
 }


    
  return 0;
}