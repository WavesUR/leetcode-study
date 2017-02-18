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
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < nums.size(); i++){
            if(q.size() >= k){
              if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
              }
            }else{
              q.push(nums[i]);
            }         
        }
        return q.top();
    }
};

int main(){

  vector<int> nums;
  nums = {3,2,1,5,6,4};
  int k = 2;
  Solution solution;
  int result = solution.findKthLargest(nums, k);

  cout << result << endl;


    
  return 0;
}