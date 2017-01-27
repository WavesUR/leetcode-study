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

// Time: O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1,0);
        int i = 1;
        int base = 1;
        while(i <= num){
            res[i] = res[i - base] + 1;
            if(i == base * 2 - 1){
                base = base * 2;
            }
            i++;
        }
        return res;
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