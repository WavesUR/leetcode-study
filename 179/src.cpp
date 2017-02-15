#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    static bool compare_string(string a, string b){
          return a + b < b + a ? true : false;
        }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++){
          strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(),strs.end(),compare_string);
        string res;
        for(int i = strs.size() - 1; i >= 0;i--){
          res = res + strs[i];
        }
        return res;
    }
};

int main(){
  vector<int> nums = {3, 30, 34, 5, 9};
  Solution solution;
  string res = solution.largestNumber(nums);
  cout << res << endl;

}