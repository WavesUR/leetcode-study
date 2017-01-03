#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	int i = nums.size();
        if(i > 1){
       	sort(nums.begin(), nums.end()); // first sort, then compare
        for(int j = 1; j < i; j++){
    		if(nums[j] == nums[j-1]){
    			return true;
    		}
    	}
        }
        return false;  
    }
};

int main(){

	vector<int> num(10);
	Solution solution;	
	bool result;

    for(int i = 0; i < 10; i++){
    	num[i] = i%10;
    }    

    for(int i = 0; i < 10; i++){
    	cout << num[i] <<" ";
    }
    cout << endl;
	result = solution.containsDuplicate(num);	
	cout << result << endl;

    
	return 0;
}