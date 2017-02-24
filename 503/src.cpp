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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        stack<int> s;
        unordered_map<int,int> map; 
        int n = nums.size();
        for(int i = 0; i < 2*n; i++ ){
          while(!s.empty() && nums[i%n] > nums[s.top()%n]){
            map[s.top()%n] = nums[i%n];
            s.pop();
          }
          s.push(i);
        }

        for(int i = 0; i < nums.size(); i++){
          if(map.find(i) == map.end()){
            res.push_back(-1);
          }else{
            res.push_back(map[i]);
          }
        }
        return res;
    }
};

int main(){

  vector<int> nums1;
  nums1 = {0,2,1,3,1,0};
  Solution solution;
  vector<int> result = solution.nextGreaterElements(nums1);

  for(auto r : result){
    cout << r << endl;
  }


    
  return 0;
}