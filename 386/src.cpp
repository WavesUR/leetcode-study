#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	vector<int> res(n);
    	int cur  = 1 ;
        for(int i = 0; i <n; i++){
        	res[i] = cur;
        	if(cur * 10 <= n){
        		cur = cur * 10;
        	}else{
        		if(cur == n){
        			cur = cur/10;
        		}
        		cur++;
        		while(cur % 10 == 0){
        			cur = cur / 10;
        		}
        	}
        }        	
        return res;
    }
};

int main(){

    int n = 29;
    Solution solution;
    vector<int> res = solution.lexicalOrder(n);
    for(auto r : res){
    	cout << r << " ";
    }
    cout << endl;

 
}