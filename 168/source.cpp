#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int base = 26;
        string s;
        do{
            s = s + char((n - 1) % base + 'A');
            n = (n - 1) / base;
        }while(n != 0);
        reverse(s.begin(),s.end());
        return s;
    }
};

int main(){
  int n = 701;
  Solution solution;

  string result = solution.convertToTitle(n);
  cout << result << endl;


    
  return 0;
}