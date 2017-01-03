#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty() || k == 0){
          return false;
        }

        unordered_map<int, int> mymap;

        for(int i = 0; i<nums.size();i++){
          if(mymap[nums[i]] != 0 && i + 1 - mymap[nums[i]] <= k){
              return true;
          }else{
            mymap[nums[i]] = i + 1;
          }
        }
//        cout << mymap[-1] << endl;
        return false; 

    }
};


int main(){


    vector<int>  nums(2);
    nums = {-1,-1};
    int k = 1;
    Solution solution;
    bool result = solution.containsNearbyDuplicate(nums,k);
    cout << result << endl;
    
  

    
	return 0;
}