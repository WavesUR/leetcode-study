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

// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        int sum = 0;
        int F = 0;
        for(int i = 0; i < len; i++){
            sum = sum + A[i];
            F = F + A[i] * i;
        }
        int max_F = F;
        for(int i = 1; i < len; i++){
            F = F + A[i-1] * (len) -(sum);
            max_F = max(max_F,F);
        }
        return max_F;
    }
};
int main(){

    vector<int> A = {4, 3, 2, 6};
    int result;
    Solution solution;
    result = solution.maxRotateFunction(A);
    cout << result << endl; 


    
	return 0;
}