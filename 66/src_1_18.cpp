#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9){
                res[i] = 0;
            }else{
                res[i] = digits[i] + 1;
                return res;
            }
        }
        res.insert(res.begin(),1);

        return res;
    }
};

int main(){


vector<int> result1(5);
result1 = {9,9,9,9,9};

Solution solution;
vector<int> result = solution.plusOne(result1);
for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
}

    
	return 0;
}