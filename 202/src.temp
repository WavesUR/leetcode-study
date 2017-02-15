#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
//#include <unordered_map>
using namespace std;


class Solution {
public:
	int sqrsum(int n){
		int sum = 0;

		while(n != 0){
			sum += pow(n%10,2);
			n = n/10;
		}
		
		return sum;
	}
    bool isHappy(int n) {
    	int result = n;
//    	unordered_map<int, int> map_count; 
		int count[10] = {};  	
     	while(result != 1){
     		if(result%10 == result){
	     		if(count[result] == 1){  			
	     			return false;
	     		}else{
	     			count[result]++;
	     		}     			
     		}

    		result = sqrsum(result);
    	}     
        return true;
    }
};

int main(){

int n = 19;

Solution solution;
bool result = solution.isHappy(n);

cout << result << endl;

    
	return 0;
}