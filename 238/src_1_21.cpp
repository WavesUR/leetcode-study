#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int product = 1;
        vector<int> result(len,1);
        for(int i = 1; i < len; i++){
            result[i] = result[i-1] * nums[i];
        }

        for(int i = len - 1; i >= 0; i--){
            result[i] = result[i] * product;
            product = product * nums[i];
        }

        return result;
    }
};

int main(){

vector<int> input;
input = {1,2,3,4};
Solution solution;
vector<int> result = solution.productExceptSelf(input);

for(int i = 0; i< result.size(); i++){
    cout << result[i] << endl;
}
 
}