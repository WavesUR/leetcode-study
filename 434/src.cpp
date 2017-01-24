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
    int countSegments(string s) {
        int count = 0;
        int flag = 0; // 1 for in segment; 0 for new segment
        for(int i = 0; i < s.length(); i++){
          if(s[i] != ' '){
            if(flag == 0){
              count++;
            flag = 1;
          }else{
            continue;
          }
          }else{
            flag = 0;
          }
        }
        return count;
    }
};

int main(){

  string s = "Hello, my name is John";
  Solution solution;
  int result = solution.countSegments(s);


  cout << result << endl;

  return 0;
}