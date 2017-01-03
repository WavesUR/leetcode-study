#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> result;
        if(len < 2){
          return result;
        }
        int first = 0;
        int last = len - 1;
        while(first < last){
          if(numbers[first] + numbers[last] == target){
            return {first+1, last+1};
          }else if(numbers[first] + numbers[last] > target){
            last--;
          }else{
            first++;
          }
        }
        return result;
    }
};

int main(){


    vector<int> nums;
    nums = {2,3,4};
    int target = 6;
    Solution solution;
    vector<int> result = solution.twoSum(nums,target);
    cout << result[0] << result[1] << endl;
    
  

    
	return 0;
}