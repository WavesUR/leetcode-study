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
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        int len = nums.size();
        if(len == 0){
          return result;
        }
        int *mymap = new int[len];
        memset(mymap, 0, sizeof(int) * len);
        vector<int> temp;
        helper(nums,temp,result,mymap);
        delete[] mymap;
        return result;
    }

    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int> >& result, int *mymap){
      if(temp.size() == nums.size()){
        result.push_back(temp);
        return;
      }

      for(int i = 0; i < nums.size(); i++){
        if(mymap[i] == 0){
          mymap[i] = 1;
          temp.push_back(nums[i]);
          helper(nums,temp,result,mymap);
          temp.pop_back();
          mymap[i] = 0;
        }
      }
    }
};
int main(){

  vector<int> nums(3);
  nums = {1 ,2 ,3};
  Solution solution;
  vector<vector<int> > result = solution.permute(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[i].size();j++){
      cout << result[i][j] << " ";
    }  
    cout << endl;
  }
  //out << result << endl;


    
  return 0;
}