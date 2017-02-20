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
        string s;
        while(n != 0){
          int temp = n % 26;
          if(temp == 0){
            s = "Z" + s;
            n = (n-26)/26; 
          }else{
            s = char(temp + 'A' - 1) + s;
            n = n / 26;
          }

        }
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