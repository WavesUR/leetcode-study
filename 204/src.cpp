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

    int countPrimes(int n) {
    	bool *isPrime = new bool[n];
    	for(int i = 2; i < n; i++){
    		isPrime[i] = true;
    	}

    	for(int i =2; i * i < n; i++){
    		if(!isPrime[i]) continue;
    		for(int j = i * i; j < n; j = j + i){
    			isPrime[j] = false;
    		}
    	}


        int count = 0;
        for(int i = 2; i < n; i++){
        	if(isPrime[i]){
        		count++;
        	}
        }
        return count;
    }
};

int main(){

int n = 7;

Solution solution;
int result = solution.countPrimes(n);

cout << result << endl;

    
	return 0;
}