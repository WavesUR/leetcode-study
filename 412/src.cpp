#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
    	vector<string> v;
        string f = "Fizz";
        string b = "Buzz";
        for(int i = 1; i <= n; i++){
        	string s;
        	s = to_string(i);
        	v.push_back(s);
        }

        for(int i = 3; i <= n; i=i+3){
        	v[i-1] = f;
        }
        for(int i = 5; i <= n; i=i+5){
        	v[i-1] = v[i-1] == f ? f+b : b;
        }

        return v;
    }
};


int main(){

int n = 15;
Solution solution;
vector<string> result = solution.fizzBuzz(n);
for(int i = 0; i < result.size();i++){
	cout << result[i] << endl;
}
    
return 0;
  
}