#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
       int map_s[10] = {0}; 
       int len = secret.length();
       int count_a = 0;
       int count_b = 0;
       for(int i = 0; i < len; i++){

        if(secret[i] == guess[i]){
          count_a++;
        }else {
          int si = secret[i] - '0';
          int gi = guess[i] - '0';
          if(map_s[si] < 0){
            count_b++;
          } 
          map_s[si]++;
          

          if(map_s[gi] > 0){
            count_b++;
          } 
          map_s[gi]--;         
      }
       }
       return to_string(count_a) + 'A' + to_string(count_b) + 'B'; 
    }
};

int main(){

  string secret = "1807";
  string guess = "7810";
  Solution solution;
  string result = solution.getHint(secret, guess);
  cout << result << endl;


    
  return 0;
}