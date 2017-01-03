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
using namespace std;

class Solution {
public:
    bool * arr;
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > vv;
        if(nums.empty()){
          return vv;
        }
        vector<int> v;
        int len = nums.size();
        arr = new bool[len]();
        sort(nums.begin(),nums.end());
        helper(vv,v,nums);
        return vv;

    }

    void helper(vector<vector<int> >& vv, vector<int>& v, vector<int>& nums){
      if(v.size() == nums.size()){
        vv.push_back(v);
        return;
      }
      int temp = INT_MIN;
      for(int i = 0; i < nums.size(); i++){
//        cout << arr[i] << endl;
        if(arr[i] == false){          
          if(i == 0 || nums[i]!=temp){
            temp = nums[i];
            v.push_back(nums[i]);
            arr[i] = true;
            helper(vv,v,nums);
            arr[i] = false;
            v.pop_back();
          }
        }
      }
    }
};

int main(){

  vector<int> nums;
  nums = {1,1,2,1};
  Solution solution;
  vector<vector<int> > result = solution.permuteUnique(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}