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


//Space: O(1)
// Time: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MinPrice = INT_MAX;
        int maxprofit = 0;
        for(int i = 0; i < prices.size();i++){
          if(prices[i] < MinPrice){
            MinPrice = prices[i];
          }else{
            maxprofit = max(maxprofit,prices[i]-MinPrice);
          }
        }
        return maxprofit;
    }
};

int main(){


    int arr[6] = {7, 1, 5, 3, 6, 4};
    vector<int> nums1(arr,arr+6);
    int result;
	Solution solution;	
 
	result = solution.maxProfit(nums1);	
    cout << result << endl;


    
	return 0;
}