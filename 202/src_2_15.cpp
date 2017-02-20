#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;

// hash Table
// class Solution {
// public:

//     bool isHappy(int n) {
// 		unordered_map<int,bool> map;    	
//         map[n] = true;
//         int sum = 0;
//         while(n!=1){
//         	while(n != 0){
//         		sum = (n%10)*(n%10) + sum;
//         		n = n /10;
//         	}
//         	if(map[sum]){
//         		break;
//         	}
//         	map[sum] = true;
//         	n = sum;
//         	sum = 0;
//         }
//         return n == 1;
//     }
// };

// ListNode
class Solution {
public:
	int helper(int n){
		int sum = 0;
        	while(n != 0){
        		sum = (n%10)*(n%10) + sum;
        		n = n /10;
        	}
        	return sum;		
	}
    bool isHappy(int n) {  	
        int slow = n;
        int fast = n;
        do{
        	slow = helper(slow);
        	fast = helper(fast);
        	fast = helper(fast);
        }while(slow != fast);
        return fast == 1;
    }
};

int main(){

int n = 19;

Solution solution;
bool result = solution.isHappy(n);

cout << result << endl;

    
	return 0;
}