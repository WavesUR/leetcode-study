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
    int firstMissingPositive(vector<int>& nums) {
    	if(nums.empty()){
    		return 1;
    	}
        int first = 0;
        int second = nums.size() - 1;
        while(first < second){
        	if(nums[first] <= 0){
        		swap(nums[first],nums[second]);
        		second--;
        	}else{
        		first++;
        	}
        }
        int end = nums[first] > 0 ? first : first - 1;

        for(int i = 0; i <= end; i++){
        	if(abs(nums[i]) - 1 <= end){
        		nums[abs(nums[i]) - 1] = - abs(nums[abs(nums[i]) - 1]);
        	}
        }
        for(int i = 0; i<= end; i++){
        	if(nums[i] > 0){
        		return i + 1;
        	}
        }
        return end + 2;
    }
};


int main(){

vector<int> nums;
nums = {0,1,2,3,-5,4};
Solution solution;
int result = solution.firstMissingPositive(nums);
cout << result << endl;
    
return 0;
  
}