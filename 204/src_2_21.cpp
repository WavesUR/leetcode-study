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
    // bool isPrimes(int n){
    //     if(n <= 1){
    //         return false;
    //     }
    //     for(int i = 2; i * i <= n; i++){
    //         if(n%i == 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    int countPrimes(int n) {
        int count = 0;
        vector<bool> map(n,true);
        for(int i = 2; i <n; i++){
            if(map[i]){               
                count++;
                int j = 2*i;
                while(j < n){
                    map[j] = false;
                    j = j + i;
                }               
            }
        }
        return count;
    }
};

int main(){

int n = 2;

Solution solution;
int result = solution.countPrimes(n);

cout << result << endl;

    
	return 0;
}