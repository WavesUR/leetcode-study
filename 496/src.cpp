#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> s;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++ ){
          while(!s.empty() && nums[i] > s.top() ){
            map[s.top()] = nums[i];
            s.pop();
          }
          s.push(nums[i]);
        }
        for(int i = 0; i < findNums.size(); i++){
          if(map.find(findNums[i]) == map.end()){
            res.push_back(-1);
          }else{
            res.push_back(map[findNums[i]]);
          }
        }
        return res;
    }
};

int main(){

  vector<int> heights, nums1;
  nums1 = {4,1,2};
  heights = {1,3,4,2};
  Solution solution;
  vector<int> result = solution.nextGreaterElement(nums1,heights);

  for(auto r : result){
    cout << r << endl;
  }


    
  return 0;
}