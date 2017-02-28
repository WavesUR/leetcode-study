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



// segment tree
class NumArray {
public:
    vector<int> inter_sum;
    vector<int> inter_nums;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        inter_nums= vector<int>(n,0);
        for(int i = 0; i <= n; i++){
            inter_sum.push_back(0);
        }
        for(int i = 0; i < n; i++){
            update(i,nums[i]);
        }
        inter_nums = nums;
    }
    
    void update(int i, int val) {
         int temp = val - inter_nums[i];  
         inter_nums[i] = val;
 //        i = i + 1;

            while(i < n){
                inter_sum[i] = inter_sum[i] + temp;
                i = i + (i & (-i));
            }
    }
    
    int sumRange(int j) { 
//        j = j + 1;
        int sum_j = 0;
         while(j >= 0){
            sum_j = sum_j + inter_sum[j];
            j = j - (j & (-j));
        }  
        return sum_j;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	vector<int> temp_num = nums;
    	sort(temp_num.begin(),temp_num.end());
    	unordered_map<int,int> dic;
    	for(int i = 0; i < temp_num.size();i++){
    		dic[temp_num[i]] = i;
    	}
        NumArray numarray(vector<int>(nums.size(),0));
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--){
        	res[i] = numarray.sumRange(dic[nums[i]]-1);
        	numarray.update(dic[nums[i]],1);
        }
        return res;
    }
};

int main(){

	
	vector<int> nums= {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
	Solution solution;
	vector<int> res = solution.countSmaller(nums);
	for(auto r : res){
		cout << r << " ";
	}
	cout << endl;

	return 0;
}