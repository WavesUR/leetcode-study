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
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int> map(len,0);
        vector<int> parent(len,0);
        int max = 0;
        int max_index = 0;

        for(int i = len - 1; i >=0; i--){
          for(int j = i; j < len; j++){
            if(nums[j] % nums[i] == 0 && map[i] < map[j] + 1){
              map[i] = map[j] + 1;
              parent[i] = j;
            }
          }
          if(map[i] > max){
            max = map[i];
            max_index = i;
          }
        }

        vector<int> result;
        for(int i = 0; i < max; i++){
          result.push_back(nums[max_index]);
          max_index = parent[max_index];
        }

        return result;
    }

};

int main(){

  vector<int> nums;
  nums = {1,2,4,7};
  Solution solution;
  vector<int> result = solution.largestDivisibleSubset(nums);
  for(int i = 0; i< result.size();i++){
    cout << result[i] << endl;
  }
//  cout << result << endl;


    
  return 0;
}