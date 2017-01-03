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
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        result[0] = 0;
        int base;
        for(int i = 1; i <= num; i++){
            if (!(i & (i-1))){
                result[i] = 1;
                base = i;
            }else{
                result[i] = result[i-base] + 1;
            }
        }
        return result;

    }
};

int main(){

int n = 8;
Solution solution;
vector<int> result = solution.countBits(n);

for(int i = 0; i< result.size(); i++){
    cout << result[i] << endl;
}
 
}