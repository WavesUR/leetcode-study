#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;
// Binary indexed tree
// class NumArray {
// public:
//     vector<int> inter_sum;
//     vector<int> inter_nums;
//     int n;
//     NumArray(vector<int> nums) {
//         n = nums.size();
//         inter_nums= vector<int>(n,0);
//         for(int i = 0; i <= n; i++){
//             inter_sum.push_back(0);
//         }
//         for(int i = 0; i < n; i++){
//             update(i,nums[i]);
//         }
//         inter_nums = nums;
//     }
    
//     void update(int i, int val) {
//          int temp = val - inter_nums[i];  
//          inter_nums[i] = val;
//          i = i + 1;

//             while(i <= n){
//                 inter_sum[i] = inter_sum[i] + temp;
//                 i = i + (i & (-i));
//             }
//     }
    
//     int sumRange(int i, int j) {
//         int sum_i = 0;
//         i  = i;
//          while(i>0){
//             sum_i = sum_i + inter_sum[i];
//             i = i - (i & (-i));
//         }  
//         j = j + 1;
//         int sum_j = 0;
//          while(j > 0){
//             sum_j = sum_j + inter_sum[j];
//             j = j - (j & (-j));
//         }  
//         return sum_j - sum_i;
//     }
// };

// segment tree
class NumArray {
public:
    vector<int> inter_sum;
    vector<int> inter_nums;
    vector<int> st;
    int n;
    int getMid(int s, int e){
    	return s + (e - s) / 2;
    }
    NumArray(vector<int> nums) {
        n = nums.size();
        if(n == 0){
        	return;
        }
        inter_nums = nums;
        int h = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2,h) - 1;
        st = vector<int>(max_size);
        constructSTUtil(nums,0,n-1,0);
        // for(auto s : st){
        // 	cout << s << " ";
        // }
    }
	int constructSTUtil(vector<int>& nums, int ss, int se, int si){
		if(ss == se){
			st[si] = nums[ss];
			return nums[ss];
		}
		int mid = getMid(ss,se);
		st[si] = constructSTUtil(nums,ss,mid,si*2+1) + constructSTUtil(nums,mid+1,se,si*2+2);
		return st[si];
	} 
	int sumRange(int qs, int qe){
		if(qs < 0 || qe > n-1 || qs > qe){
			return INT_MIN;
		}

		return getsumUtil(0,n-1,qs,qe,0);

	}   
	int getsumUtil(int ss, int se, int qs,int qe, int si){
		if(qs <= ss && qe >= se){
			return st[si];
		}
		if(se < qs || ss > qe){
			return 0;
		}
		int mid = getMid(ss,se);
		return getsumUtil(ss,mid,qs,qe,si*2+1) + getsumUtil(mid+1,se,qs,qe,si*2+2);
	}
	void update(int i, int val){
		int diff = val - inter_nums[i];
		inter_nums[i] = val;
		updateUtil(0,n-1,i,diff,0);
	}
	void updateUtil(int ss, int se,int i, int diff, int si){
		if(i < ss || i > se){
			return;
		}

		st[si] = st[si] + diff;
		if(se != ss){
			int mid = getMid(ss,se);
			updateUtil(ss,mid,i,diff,si*2+1);
			updateUtil(mid+1,se,i,diff,si*2+2);
		}
	}

};


int main(){

	
	vector<int> nums= {1,3,5};
	NumArray numarray(nums);
	int res = numarray.sumRange(0,2);
	cout << res << endl;
	numarray.update(1,2);
	res = numarray.sumRange(0,2);
	cout << res << endl;

	return 0;
}