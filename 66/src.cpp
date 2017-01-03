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
    	for(int i = digits.size() - 1; i >= 0 ; i--){
    		if(digits[i] < 9){
    			digits[i] +=1;
    			return digits;
    		}
    		digits[i] = 0;
    	}
    	digits.insert(digits.begin(),1);
    	return digits;
    }
};

int main(){

vector<int> result1;

Solution solution;
vector<int> result = solution.plusOne(result1);
//cout << result << endl;

    
	return 0;
}