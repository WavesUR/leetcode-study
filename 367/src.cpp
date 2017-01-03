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


class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        int c;
        while(l<=r){
          c = l + (r-l)/2;
          if(c < num/c){
            l = c + 1;
          }else if(c > num/c){
            r = c - 1;
          }else if(num%c == 0){
            return true;
          }else{
            return false;
          }
        }
        return false;
    }
};

int main(){


    int num = 5;
    Solution solution;
    bool result = solution.isPerfectSquare(num);
    cout << result << endl;
    
  

    
	return 0;
}