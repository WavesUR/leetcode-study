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

class Solution {
public:
    int numSquares(int n) {
        
        return helper(n);
    }
    int helper(int n){
    	static int mins[1000000] = {0};
    	for(int i = 1; i <= n; i++){
    		int min = INT_MAX;
    //		int square = 1;
    		if(mins[i]){
    			continue;
    		}
    		for(int r = 1; r*r <= i; r++){
    			int t = mins[i-r*r] + 1;
    			min = t < min ? t : min;
//    			square = r*r;
    		}
    		mins[i] = min;
    	}
    	return mins[n];
    }
};
int main(){

  int n = 12;
  Solution solution;
  int result = solution.numSquares(n);
  cout << result << endl;


    
  return 0;
}