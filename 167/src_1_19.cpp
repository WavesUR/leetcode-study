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
        int start = 0, end = numbers.size() -1;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                return {start+1,end+1};
            }else if(numbers[start] + numbers[end] > target){
                end--;
            }else{
                start++;
            }
        }
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